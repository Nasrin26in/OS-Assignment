#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>



int main(int arguments, char* arg[])
{
    int noOfFile[2]; //file descriptor array reading 0 writing 1
    pid_t copyProcess; // declare copy process
    int size=100;
    char buffer[size]; // creating buffer of size 100, text length
    pipe(noOfFile); // creating pipe
    if( arguments != 3 ) // check to arguments are passed or not  after  gcc filecopy.c -o cp
    {
        printf("ERROR: Pass 2 parameters.\n");
        exit(1);
    }
    // .cp input.txt copy.txt  arg[1] is input.txt arg[2] is copy.txt
    int srcFileOpen = open(arg[1], 0); // opening file input.txt from where we have to copy
    int targetFileOpen = open(arg[2], O_RDWR|O_CREAT|O_APPEND, 0666);// opening copy.txt to where we have to copy
    if (srcFileOpen == -1 || targetFileOpen == -1) // check whether file is opened or not
    {
        printf("File cannot be opend\n");
        exit(1);
    }
    copyProcess = fork(); // creating child process
    if (copyProcess == 0) // if child process
    {
        close(noOfFile[1]);
	while (read(noOfFile[0], buffer, sizeof(buffer)) > 0) // read that file till there is content
	{
		write(targetFileOpen, buffer, strlen(buffer) - 1);  // write in taeget file
        }
        close(noOfFile[0]);
        close(targetFileOpen); // close target file
    }
    else // if not child
    {
        close(noOfFile[0]);
	while (read(srcFileOpen, buffer, sizeof(buffer)) > 0) // read that file till there is content
	{
            write(noOfFile[1], buffer, sizeof(buffer)); // write in taeget file
            memset(buffer, 0, size); //memorize buffer 
        }
        close(noOfFile[1]);
        close(srcFileOpen); // close source file
        wait();

    }
}
