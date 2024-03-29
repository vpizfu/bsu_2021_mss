#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    struct stat sb;
    int fd_1, fd_2;
    long long size_1 = 0;
    long long size_2 = 0;
    char* filename_1 = argv[1];
    char* filename_2 = argv[2];
    if((fd_1=open(filename_1, O_RDWR))==-1) {
        printf("Cannot open file.\n");
        exit(1);
    }
    
    if((fd_2=open(filename_2, O_RDWR))==-1) {
        printf("Cannot open file.\n");
        exit(1);
    }
    
    if (stat(filename_1, &sb) == -1) {
        perror("stat");
    }
    else {
        size_1 = sb.st_size;
        printf("File size: %lld bytes\n", size_1);
    }
    
    if (stat(filename_2, &sb) == -1) {
        perror("stat");
    }
    else {
        size_2 = sb.st_size;
        printf("File size: %lld bytes\n", size_2);
    }
    
    char buffer_1[size_1];
    char buffer_2[size_2];
    
    if (read(fd_1, buffer_1, size_1))
        printf ("Buffer: %s\n", buffer_1);
    
    if (read(fd_2, buffer_2, size_2))
        printf ("Buffer: %s\n", buffer_2);
    
    
    if (close(fd_1))
        printf ("Succesfull closed %d file\n", fd_1);
    
    if (close(fd_2))
        printf ("Succesfull closed %d file\n", fd_2);
    
    if((fd_1=open(filename_1, O_WRONLY | O_TRUNC))==-1) {
        printf("Cannot open file.\n");
        exit(1);
    }
    
    if((fd_2=open(filename_2, O_WRONLY | O_TRUNC))==-1) {
        printf("Cannot open file.\n");
        exit(1);
    }
    
    if (stat(filename_1, &sb) == -1) {
        perror("stat");
    }
    else {
        size_1 = sb.st_size;
        printf("File size: %lld bytes\n", size_1);
    }
    
    if (stat(filename_2, &sb) == -1) {
        perror("stat");
    }
    else {
        size_2 = sb.st_size;
        printf("File size: %lld bytes\n", size_2);
    }

    if(write(fd_2, buffer_1, strlen(buffer_1)))
        printf ("Succesfull write %d file\n", fd_2);
    
    if(write(fd_1, buffer_2, strlen(buffer_2)))
        printf ("Succesfull write %d file\n", fd_1);
    
    if (close(fd_1))
        printf ("Succesfull closed %d file\n", fd_1);
    
    if (close(fd_2))
        printf ("Succesfull closed %d file\n", fd_2);
    
    return 0;
}
