#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
	int fd=open("log.txt", O_WRONLY | O_APPEND);
	if(fd<0)
	{
		perror("Open");
		return 1;
	}
	char details[]="Age:22\nCollege:NIET\n";
	write(fd,details,sizeof(details));
	return 0;
}
