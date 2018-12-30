#include <stdio.h>

#define MAX_LENGTH 100

void rev(char s[]) {
	int len = 0;
	while (s[len] != '\0') {
		len++;
	}
	for (int i = 0; len - 1 - i > i; i++) { 
		char temp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = temp;
	}
}

void add(char s1[], char s2[], char sum[]) {
	for (int i = 0; i < MAX_LENGTH; i++) {
		sum[i] = '0';
	}
	sum[MAX_LENGTH] = '\0';
	for (int i = 0; s1[i] != '\0'; i++) {
		sum[i] += s1[i] - '0';
	}
	for (int i = 0; s2[i] != '\0'; i++) {
		sum[i] += s2[i] - '0';
	}
	int lastZero;
	for (lastZero = MAX_LENGTH - 1; lastZero > 0; lastZero--) {
		if (sum[lastZero] != '0') {
			break;
		}
	}
	sum[lastZero + 1] = '\0';
}

void bin(char s[]) {
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] >= '2') {
			if (s[i + 1] == '\0') {
				s[i + 1] = '0';
				s[i + 2] = '\0';
			}
			s[i + 1] += (s[i] - '0') / 2;
			s[i] = (s[i] - '0') % 2 + '0';
		}
	}
}

int main()
{
	char s1[MAX_LENGTH + 1], s2[MAX_LENGTH + 1], sum[MAX_LENGTH + 1];
	scanf("%s %s", s1, s2);
	rev(s1);
	rev(s2);
	add(s1, s2, sum);
	bin(sum);
	rev(sum); 
	printf("%s\n", sum);
	return 0;
}
