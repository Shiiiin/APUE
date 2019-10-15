#include <stdio.h>
#include <fcntl.h>

#define MIN 1
#define MAX 1024
#define BUFSIZE 16
int main(){

	int i = 0;
	int fd = 0;
	int desc = 0;

	for(i = MIN; i < MAX+1; i++){

		char filename[BUFSIZE];
		char buf[BUFSIZE];

		sprintf(filename, "./%d.dat", i);
	
		if( (fd = open(filename, O_RDWR | O_CREAT, 0777)) < 0){;
		
			printf("%d", fd);

			desc = read(fd, 0, buf, BUFSIZE);

			if(desc == 0){
				write(filename, 1, BUFSIZE);
			}else{
				write(filename, desc++, BUFSIZE);
			}
		
		}

	}

	return 0;
}

/*
void setString(const char *ap_string){

	char *p_str;

	int len
}
no files named 1.dat~1024.dat -> creat


if there is a file
	if no content, put 1
	otherwise, increment it.
	if the content is 10, remove it
*/
