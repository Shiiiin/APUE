#include <stdio.h>
#include <signal.h>

int delay;
void childHandler();

main(int argc, char *argv[])
{
	int pid;

	sscanf(argv[1], "%d", &delay);
	signal(SIGCHLD, childHandler);

	pid = fork();
	printf("%d asdf\n", pid);
	if ( pid == 0 ) { //child
		execvp(argv[2], &argv[2]);
		perror("Limit");
	} else {
		sleep(delay);
		printf("Child %d exceeded limit and is being killed\n", pid);
		kill(pid, SIGINT);
	}
}

childHandler()
{
	int childPid, childStatus;
	printf("childSatus %d\n", &childStatus);
	childPid = wait(&childStatus);
	printf("Child %d terminated within %d seconds\n", childPid, delay);
	exit(0);
}
