#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
void mytolower(char *line){
	char *ptr=line;
	while(*ptr&&*ptr!=NULL){
		*ptr++=tolower(*ptr);
	}
	*ptr='\0';
}

int main(int argc,char **argv){
	int fdo = open(argv[1], O_RDWR | O_CREAT);
	int fdw = open(argv[2], O_RDWR | O_CREAT);
	char *r = (char *)calloc(10, sizeof(char));
	char *w = (char *)calloc(10, sizeof(char));
	int sz=1;
	while(sz!=0){
		sz = read(fdo, r, 10);
		r[sz]='\0';
		mytolower(r);
		write(fdw, r, strlen(r));
	}
	close(fdo);
	close(fdw);
}
