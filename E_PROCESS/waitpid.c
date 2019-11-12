#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
	pid_t pid;
	int status;

	if( (pid = fork()) == 0 )
	{
		printf("I am a child with pid = %d\n",getpid());
		sleep(60);
		printf("child terminates\n");
		return 0;
	}
	else
	{
		while(1)
		{
			waitpid( pid, &status, WUNTRACED );
			if ( WIFSTOPPED(status) )
			{
				printf("child stopped, signal(%d)\n",WSTOPSIG(status));
				continue;
			}
			else if( WIFEXITED(status) )
				printf("normal termination with	status(%d)\n",WEXITSTATUS(status));
			else if ( WIFSIGNALED(status))
				printf("abnormal termination, signal(%d)\n", WTERMSIG(status));
			return 0;
		
		}
	}
}
