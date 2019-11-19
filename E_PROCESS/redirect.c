#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	int fileId;
	fileId = creat( "x.lis", 0640 );
	if( fileId < 0 )
	{
		printf("error creaing x.lis\n" );
		exit(1);
	}
	dup2( fileId, STDOUT_FILENO );
	close( fileId );
	execl( "/bin/ls", "ls", 0 );
}
