#include <stdio.h>
#include <fcntl.h>
#include <malloc.h>

#define MIN 1
#define MAX 1024
#define BUFSIZE 2056

int main(){

	int i = 0;

	for(i = MIN; i < MAX+1; i++){

		char filename[BUFSIZE];
		char buf[2] = {0xff};
		int fd = 0;
		int num = 0;
		int byteNum = 0;

		sprintf(filename, "./%d.dat", i);
	
		if( (fd = open(filename, O_RDWR)) < 0){

			creat(filename, 0777);
			printf("create a file\n");
			continue;

		}
		
		if ( (byteNum = read(fd, buf, sizeof(buf))) <0)
		{
			perror("failed read\n");
			return -1;
		}
		
		if( buf == 0){

			num = 1;
			sprintf(buf, "%d", num);

			if((write(fd, buf, sizeof(buf))) < 0)
			{
				perror("failed write\n ");		
				return -1;
			}		
		}else{
			
			num = atoi(buf);
			num++;

			if ( num == 10){

				if( (remove(filename)) == 0){
					printf("file removed\n");
					continue;
				}else{
					printf("failed to remove the file\n");
					return -1;
				}
					
			}else{
				sprintf(buf, "%d", num);
				lseek(fd, SEEK_SET, 0);
				write(fd, buf, sizeof(buf));
			}
		}
		
	close(filename);

	}

	printf("success\n");

	return 0;
}
