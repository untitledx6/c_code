/*#include <stdio.h>
int main(void)
{
	char c[5][80];
	char a;
	int i = 0, j = 0;
	while (1) {
		a = getchar();
		if (a == ' ' || a == '\n') {
			i++;
			c[i][j] = '\0';
			j = 0;
			if (i == 5)
				break;
			continue;
		}
		c[i][j] = a;
			j++;
	}
	for(int m = 0; m < 4; m++){
		for(int n = 1; n < (5 - m); n++){
			for(int t = 0; (c[n][t] != '\0') && (c[n-1][t] != '\0'); t++){
				if(c[n][t] == c[n - 1][t]){
					continue;
				}
				 else if(c[n][t] < c[n - 1][t]){
					for(int aa = t; aa < 80; aa++){
						char temp = c[n][aa];
						c[n][aa] = c[n - 1][aa];
						c[n - 1][aa] = temp;
					}
					break;
				}
				else{
					break;
				}
			}
		}
	}for (int x = 0; x < 5; x++) {
		for (int y = 1; y < 5; y++) {
			if (c[y][1] <= c[y - 1][1]) {
				int temp = num[y];
				num[y] = num[y - 1];
				num[y - 1] = temp;
			}
		}
	}
	printf("After sorted:\n");
	for (int xx = 0; xx < 5; xx++) {
		for (int yy = 0; c[xx][yy] != '\0'; yy++) {
			putchar(c[xx][yy]);
		}
		if (xx < 4)
		printf("\n");
	}
	return 0;
}
*/
