#include<stdio.h>
int main() {
	int n, a[500]={0}, b;
		scanf("%d",&n);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				scanf("%d",&b);
				a[j] = a[j] + b;
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
		printf("\n");
	return 0;
}
