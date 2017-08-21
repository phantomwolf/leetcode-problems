#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define ERR_BUFF_SIZE 256

int mydup2(int oldfd, int newfd)
{
    char err_buff[ERR_BUFF_SIZE];
    // Get max open file limit
    rlim_t max_open;
    struct rlimit limit;
    if (getrlimit(RLIMIT_NOFILE, &limit) == 0) {
        max_open = limit.rlim_max;
    } else {
        switch (errno) {
            case EFAULT:
            case EINVAL:
                strerror_r(errno, err_buff, ERR_BUFF_SIZE);
                fprintf(stderr,
                        "Failed to get max open file limit: %s\n",
                        err_buff);
                break;
        }
        max_open = 4096;
    }
    // check if newfd is valid
    if (newfd < 0 || newfd >= max_open) {
        errno = EBADF;
        strerror_r(errno, err_buff, ERR_BUFF_SIZE);
        fprintf(stderr,
                "%d is not a valid file descriptor: %s\n",
                newfd,
                err_buff);
        return -1;
    }
    // if newfd is open, close it
    int fd;
    if ((fd = dup(newfd)) != -1) {
        if (close(fd) == -1 || close(newfd) == -1) {
            strerror_r(errno, err_buff, ERR_BUFF_SIZE);
            fprintf(stderr,
                    "Failed to close fd %d, %d: %s\n",
                    fd,
                    newfd,
                    err_buff);
            return -1;
        }
    } else {
        switch(errno) {
            case EBADF:
                // newfd not open
                break;
            case EMFILE:
                if (close(newfd) == -1) {
                    strerror_r(errno, err_buff, ERR_BUFF_SIZE);
                    switch (errno) {
                        case EBADF:
                            fprintf(stderr,
                                    "Failed to close file descriptor %d: %s\n",
                                    newfd,
                                    err_buff);
                            break;
                    }
                    return -1;
                }
            default:
                strerror_r(errno, err_buff, ERR_BUFF_SIZE);
                fprintf(stderr,
                        "Failed to dup fd %d: %s\n",
                        newfd,
                        err_buff);
                return -1;
        }
    }
    // dup until we get the correct fd
    int n;
    int* fds = (int*)calloc(max_open, sizeof(int));
    for (n=0; n < max_open; ++n) {
        if ((fds[n] = dup(oldfd)) == -1) {
            switch (errno) {
                case EMFILE:
                case EBUSY:
                case EBADF:
                    newfd = -1;
                    break;
            }
        } else if (fds[n] == newfd)
            break;
    }
    while (n > 0) {
        --n;
        if (close(fds[n]) == -1) {
            strerror_r(errno, err_buff, ERR_BUFF_SIZE);
            fprintf(stderr,
                    "Failed to close fd %d: %s\n",
                    fds[n],
                    err_buff);
        }
    }
    free(fds);
    return newfd;
}

int main()
{
    int fd;
    fd = dup2(1, 9);

    int newfd;
    newfd = mydup2(1, 28);
    printf("New fd is %d\n", newfd);
    fflush(stdout);
    write(newfd, "hello\n", 6);
    return 0;
}
