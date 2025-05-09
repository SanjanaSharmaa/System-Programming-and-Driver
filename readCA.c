#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

int main()
{
	int fd=open("log.txt", O_RDONLY);
	if(fd<0)
	{
		perror("Open");
		return 1;
	}
	char buffer[200];
	int bytes=read(fd,buffer,sizeof(buffer));
	if(bytes>0)
	{
		write(1,buffer,bytes);
	}
	close(fd);
	return 0;
}
