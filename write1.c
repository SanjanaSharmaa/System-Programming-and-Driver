#include <fcntl.h> //open()
#include<unistd.h>
#include<stdio.h>

int main()
{
	int fd=open("file.txt", O_CREAT | O_WRONLY, 0644);//0644 is used to determine the mode i.e. read, write,execute
	if(fd<0)
	{
		perror("Open");
		return 1;
	}
	char msg[]="Hello System Programming!\n";
	write(fd, msg, sizeof(msg)-1);
	close(fd);
	return 0;

}
