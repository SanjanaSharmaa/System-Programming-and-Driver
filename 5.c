#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int i;
	for(i=0;i<3;i++)
	{
		pid_t pid =fork();
		if (pid==0)
		{
			printf("Child %d:PID=%d\n",i+1,getpid());
			return 0;
		}
	}
	for(i=1;i<3;i++)
	{
		wait(NULL);
		printf("Parent: All children finished.\n");
	}
	return 0;
}
