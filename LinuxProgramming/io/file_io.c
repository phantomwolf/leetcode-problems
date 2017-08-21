#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

#define FILE_PATH "/tmp/test"

int main(int argc, char* argv[])
{
    /* create a file and write */
    int fd;
    ssize_t n, bytes = 0;
    char* buff = "Linux prevails!";

    if ((fd = open(FILE_PATH,
                   O_CREAT | O_WRONLY,
                   S_IRUSR | S_IWUSR | S_IRGRP)) >= 0) {
        /* write data into it */
        do {
            n = write(fd, buff + bytes, strlen(buff) - bytes);
            if (n < 0) {
                fprintf(stderr, "Failed to write to file %s\n", FILE_PATH);
                return 1;
            }
            bytes += n;
        } while(bytes < strlen(buff));
        /* close file */
        close(fd);
        return 0;
    }
    switch (errno) {
        case EACCES:
            puts("Permission denied!");
            break;
        default:
            puts("Unknown error!");
    }
    return 0;
}
