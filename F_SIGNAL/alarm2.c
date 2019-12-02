#include <stdio.h>
#include <signal.h>

int alarmFlag=0;
void alarmHandler();

main()
{
	signal(SIGALRM, alarmHandler);
	alarm(3);
	printf("Looping... \n");
	while(!alarmFlag) {
		pause();
	}
	printf("Loop ends due to alarm signal \n");
}

void alarmHandler(){
	printf("An alarm clock signal was received\n");
	alarmFlag = 1;
}
