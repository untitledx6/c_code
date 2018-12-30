#include<stdio.h>
int main(void){
	int n;
	scanf("%d",&n);
	int a[n],b;
	for(int i = 0; i < n; i++)
		a[i] = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d",&b);
			if(b == 1)
			a[j]++;
		}
	}
	int temp = 0;
	for(int i = 0; i < n; i++){
		if(a[i] * 2 > n && temp == 0){
			printf("%d",i + 1);
			temp = 1;
			continue;
		}
		if(a[i] * 2 > n && temp == 1){
			printf(" %d",i + 1);
		}
		
	}
	return 0;
}
