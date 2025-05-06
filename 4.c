#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
        pid_t pid = fork();
        if(pid == 0)
        {
                printf("Child is counting:\n");
                for(int i=1;i<=5;i++)
                {
                        printf("Child:%d\n",i);
                        sleep(1);
                }
        }
        else
        {
		wait(NULL);
                printf("Parent is counting:\n");
                for(int i=10;i<=50;i+=10)
                {
                        printf("Parent:%d\n",i);
                        sleep(1);
                }
        }
        return 0;
}
