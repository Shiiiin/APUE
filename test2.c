#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void (*old_fun)( int);

void sigint_handler(int signo)
{
	signal( SIGINT, old_fun);
}

int main()
{
	pid_t pid;
	pid = fork();
	
	old_fun = signal( SIGINT, sigint_handler);

	if(pid==0)
	{
		for(;;){
	
		old_fun = signal( SIGINT, sigint_handler);

		system("curl https://www.naver.com");
				
		}
	}

return 0;
}
