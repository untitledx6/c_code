#include<stdio.h>
void search(int *s,int n, int a,int b);
int main(void){
	int n,a,b;
	int s[n];
	scanf("%d %d %d",&n,&a,&b);
	for(int i = 0; i < n; i++){
		scanf("%d",&s[i]);
	}
	search(s,n,a,b);
	return 0;
}
void search(int *s,int n, int a,int b){
	if(a == b)
	return;
	if(a - s[a-1] > 0) 
	search(s,n,a - s[a-1],b);
	if(a + s[a-1] <= n)
	search(s,n,a + s[a-1],b);
	return;
}
