#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>



int main(int arguments, char* arg[])
{
    int noOfFile[2];
    pid_t copyProcess;
    int size=100;
    char buffer[size];
    pipe(noOfFile);
    if( arguments != 3 )
    {
        printf("ERROR: Pass 2 parameters.\n");
        exit(1);
    }
    int srcFileOpen = open(arg[1], 0);
    int targetFileOpen = open(arg[2], O_RDWR|O_CREAT|O_APPEND, 0666);
    if (srcFileOpen == -1 || targetFileOpen == -1)
    {
        printf("File cannot be opend\n");
        exit(1);
    }
    copyProcess = fork();
    if (copyProcess == 0)
    {
        close(noOfFile[1]);
	while (read(noOfFile[0], buffer, sizeof(buffer)) > 0)
	{
		write(targetFileOpen, buffer, strlen(buffer) - 1);
        }
        close(noOfFile[0]);
        close(targetFileOpen);
    }
    else
    {
        close(noOfFile[0]);
	while (read(srcFileOpen, buffer, sizeof(buffer)) > 0)
	{
            write(noOfFile[1], buffer, sizeof(buffer));
            memset(buffer, 0, size);
        }
        close(noOfFile[1]);
        close(srcFileOpen);

    }
}
