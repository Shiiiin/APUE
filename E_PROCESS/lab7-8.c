#include <stdio.h>
#include <string.h>

#define READ 0
#define WRITE 1

char* phrase = "Stuff this in your pipe and smoke it" ;

main() {
	int fd[2], bytesRead;
	char message[100];
	pipe(fd);
	if (fork() == 0) {
		close(fd[READ]);
		write(fd[WRITE], phrase, strlen(phrase)+1);
		fprintf(stdout, "[%d, child] write completed.\n", getpid());
		close(fd[WRITE]);
	}
	else {
		close(fd[WRITE]);
		bytesRead = read(fd[READ], message, 100);
		fprintf(stdout, "[%d, parent] read completed. \n", getpid());
		printf("Read %d bytes: %s\n", bytesRead,message);
		close(fd[READ]);
	}
}
