#include<stdio.h>
int main(void){
	int n,sum0 = 0,sum1 = 0;
	scanf("%d",&n);
	int a[n][n];
	for(int i = 0; i < n; i++)
	for(int j = 0; j < n; j++)
	scanf("%d",&a[i][j]);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[j][i] == 1){
				sum1++;
			}else{
				sum0++;
			}
		}
		if(sum1 > sum0){
			for(int j = 0; j < n; j++){
				if(a[j][i] == 0){
					a[j][i] = -1;
				}
			}
		}else{
			for(int j = 0; j < n; j++){
				if(a[j][i] == 1){
					a[j][i] = -1;
				}
			}
		}
		sum1 = 0;
		sum0 = 0;
	}
	int temp = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[i][j] == -1){
				break;
			}
			if(j == n - 1 && temp == 0){
				printf("%d",i + 1);
				temp = 1;
				break;
			}
			if(j == n - 1 && temp == 1){
				printf(" %d",i + 1);
			}
		}
	}
	return 0;
}/*
6
1 1 1 1 1  1
1 1 0 0 0 0 
1 0 0 0 0 0 
1 1 1 1 1 1 
1  0 1 0 1 0
 1 0  1 0 1 0
 */


