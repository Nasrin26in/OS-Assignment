/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <unistd.h>

int main()
{


	int userEntry=0; // user entered number declare  initialize from 0

	pid_t pid; // declare procesid


		do   // check user entered number greater than zero
		{
			printf("NOTE! Enter a number greater than 0.\n");
  			scanf("%d", &userEntry);
		}while (userEntry <= 0); // untill user entered less than zero it will take input or execute do statement
		pid = fork(); // creating new process that is child process

		if (pid == 0) // pid = 0 implies child started
		{
			printf("Child Process Started...\n");
			printf("%d\n",userEntry);
			while (userEntry!=1)
			{
				if (userEntry%2 == 0)
				{
					userEntry = userEntry/2;  // if number is even half it
				}
				else
				{
					userEntry = 3 * (userEntry) + 1; // else multiply 3  and add 1
				}

				printf("%d\n",userEntry);
			}

            printf("Child process Ended.\n");
            printf("*************************.\n");

		}
		else
		{   printf("----------------------------.\n");
			printf("Parent process started  and is waiting for child process to end ...\n");
			wait(); // wait for child to end
			printf("Parent process Ended.\n");
			printf("----------------------------.\n");
		}
	return 0;
}
