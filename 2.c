//Fork Example
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
 int main()
{
	pid_t pid;
	pid=fork();

	if(pid<0)
	{
		perror("Fork Failed");
		return 1;
	}
	else if(pid==0)
	{
		printf("This is the child process. PID:%d\n", getpid());
	}
	else
	{
		printf("This is the parentprocess. PID:%d, Child PID:%d\n", getpid(), pid);

	}
	return 0;
}
