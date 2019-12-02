#include <signal.h>
#include <stdio.h>
#include <unistd.h>

main() {
	
	register int i;
	setpgrp();
	int pid;
	
	for (i=0;i<10;i++){
		
		if( (pid = fork())!= -1 ) {
			
			/* child process */
			if(i&1) setpgrp();
			printf("pid = %d pgrp = %d\n", getpid(), getpgrp() );
			pause();
		}
	}

	kill(0,SIGINT);
}
