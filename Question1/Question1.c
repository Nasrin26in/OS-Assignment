/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <unistd.h>

int main()
{


	int userEntry=0;

	pid_t pid;


		do
		{
			printf("NOTE! Enter a number greater than 0.\n");
  			scanf("%d", &userEntry);
		}while (userEntry <= 0);

		pid = fork();

		if (pid == 0)
		{
			printf("Child Process Started...\n");
			printf("%d\n",userEntry);
			while (userEntry!=1)
			{
				if (userEntry%2 == 0)
				{
					userEntry = userEntry/2;
				}
				else if (userEntry%2 == 1)
				{
					userEntry = 3 * (userEntry) + 1;
				}

				printf("%d\n",userEntry);
			}

            printf("Child process Ended.\n");
            printf("*************************.\n");

		}
		else
		{   printf("----------------------------.\n");
			printf("Parent process started  and is waiting for child process to end ...\n");
			wait();
			printf("Parent process Ended.\n");
			printf("----------------------------.\n");
		}
	return 0;
}
