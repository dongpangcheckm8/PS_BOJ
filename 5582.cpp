// #5582 공통 부분 문자열
https://www.acmicpc.net/problem/5582

#include <stdio.h>

char S1[4003], S2[4003];
int dp[4002][4002];
int res;

int max(int a, int b) { return (a > b) ? a : b; }

void make_LCS(void) {
	for (int i = 1; S1[i]; i++) {
		for (int j = 1; S2[j]; j++) {
			if (S1[i] == S2[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				res = max(res, dp[i][j]);
			}
		}
	}
}

int main(void) {
	scanf("%s", S1 + 1);
	scanf("%s", S2 + 1);
	make_LCS();
	printf("%d\n", res);
	return 0;
}
