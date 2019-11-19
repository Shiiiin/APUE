#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include "../apue/apue.h"

void printpos(char *msg, int fd);

int main(void)
{
	int fd;
	pid_t pid;
	char buf[10];
	
	if ((fd=open("data-file", O_RDONLY)) < 0)
		printf("open error");

	read(fd, buf, 10);

	printpos( "Before fork", fd);

	if( (pid = fork() ) == 0 )
	{
		printpos( "Child before read", fd );
		read( fd, buf, 10 );
		printpos( "Child after read", fd );
	}
	else if( pid > 0 )
	{
		wait((int *)0);
		printpos( "Parent after wait", fd );
	}
	else
		printf( "fork" );
}

void printpos( char *msg, int fd )
{
	long int pos;

	if( (pos = lseek(fd, 0L, SEEK_CUR) ) < 0L )
		printf("lseek");

	printf("%s: %ld\n", msg, pos );
}
