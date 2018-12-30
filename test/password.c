#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main(void){
	int i=0;
	char *password = (char *)malloc(20*sizeof(char));
	do{
		password[i] = getch();
		printf("*");
		i++; 
		if(i == 19){
			printf("password too long!\n");
			
			exit(1);
		}
	}while(password[i - 1] != '\r');//»òwhile(password[i - 1] != '\r');
	password[i - 1] = '\0';
	printf("\n");
	puts(password);
	free(password);
	return 0;
}

