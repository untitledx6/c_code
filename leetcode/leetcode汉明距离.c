#include<stdio.h>
#include<stdlib.h>
int hammingDistance(int x,int y);
int main(void){
	int x,y;
	scanf("%d %d",&x,&y);
	printf("%d\n",hammingDistance(x,y));	
	return 0;
}
	int hammingDistance(int x, int y) {
    int num=0;
    int lena;
    char *a=malloc(100*sizeof(char));
    for (int i=0;x%2!=0||x/2!=0;i++){
        a[i]='0'+x%2;
        x=(x-x%2)/2;
        lena = i + 1;
    }
    for (int i=lena;i<99;i++){
        a[i]='0';
    }
    a[99]='\0';
        int lenb;
    char *b=malloc(100*sizeof(char));
    for (int i=0;y%2!=0||y/2!=0;i++){
        b[i]='0'+y%2;
        y=(y-y%2)/2;
        lenb = i + 1;
    }
    for (int i=lenb;i<99;i++){
        b[i]='0';
    }
    b[99]='\0';
    for(int i = 0;i<99;i++){
        if(a[i]!=b[i]){
        num++;
        }
    }
    return num;
}
