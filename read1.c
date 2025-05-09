#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

int main()
{
	int fd=open("file1.txt", O_RDONLY);
	if(fd<0)
	{
		perror("open");
		return 1;
	}
	char buffer[100];
	int bytes=read(fd,buffer,sizeof(buffer));
	write(1,buffer,bytes);
	close(fd);
	return 0;
}
