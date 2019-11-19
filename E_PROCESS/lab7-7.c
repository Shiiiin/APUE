#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdlib.h>

int main ( int argc, char* argv[]) {
	char *path = "/bin/ls";
	char *arg0 = "ls";
	pid_t pid;
	int fd;
	int status;

	if ( argc!=2 ) {
		printf("wrong command. ex) a.out filename\n");
		exit(0);
	}

	pid = fork();
	if (pid == 0) {
		fd = open( argv[1], O_WRONLY|O_CREAT|O_TRUNC, S_IRWXU) ;
		dup2(fd, STDOUT_FILENO);
		close(fd);
		if (execl(path, arg0, NULL ) == -1)
			printf("execl");
	} else {
		close(fd);
		wait(&status);
	}
}

