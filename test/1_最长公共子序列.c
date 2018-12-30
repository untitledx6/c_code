#include<stdio.h>
int f(int *a, int *b, int m, int n);
int main(void){
	int m,n;
	scanf("%d %d",&m,&n);
	int a[m],b[n];
	for(int i = 0; i < m; i++)
		scanf("%d",&a[i]);
	for(int i = 0; i < n; i++)
		scanf("%d",&b[i]);
	printf("%d\n",f(a, b, m, n));
	return 0;
}
int f(int *a, int *b, int m, int n){
	if(m == 0 || n == 0)
		return 0;
	if(a[m-1] == b[n-1]){
		return 1 + f(a, b, m - 1, n - 1);
	}else{
		return f(a, b, m - 1, n) > f(a, b, m, n - 1) ? f(a, b, m - 1, n) : f(a, b, m, n - 1);
	}
}
