#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

int main()
{
	int fd=open("log.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);//O_TRUNC is for overwriting
	if(fd<0)
	{
		perror("Open");
		return 1;
	}
	char name[]="Sanjana Sharma\n";
	write(fd,name,sizeof(name));
	close(fd);
	return 0;
}
