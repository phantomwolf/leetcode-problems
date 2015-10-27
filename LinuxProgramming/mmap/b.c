#include <sys/types.h>
#include <sys/mman.h>
#include <err.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
    char str[] = "Baka!";
    int fd; 
    char *area;

    if ((fd = open("data.txt", O_RDWR, 0)) == -1) {
        err(1, "open");
    }   

    area = (char *)mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0); 
    if (area == MAP_FAILED)
        errx(1, "either mmap");
    // Read data
    printf("Old: %s\n", area);
    // Write data
    strcpy(area, str);

    printf("New: %s\n", area);

    munmap(area, 4096);

    return EXIT_SUCCESS;
}
