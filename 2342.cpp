// #2342 Dance Dance Revolution
https://www.acmicpc.net/problem/2342

#include <stdio.h>
#include <cstring>

const int INF = 500000;
int pos[100001], dp[100001][5][5];

int min(int a, int b) { return (a < b) ? a : b; }
int abs(int a) { return (a >= 0) ? a : -a; }

int cost(int x, int y) {
	if (x == 0) return 2;
	else if (abs(x - y) == 1 || abs(x - y) == 3) return 3;
	else if (abs(x - y) == 2) return 4;
	return 1;
}

int main(void) {
	int len;
	for (len = 1; ; len++) {
		scanf("%d", &pos[len]);
		if (pos[len] == 0) break;
	}
	len--;
	memset(dp, INF, sizeof(dp));
	dp[0][0][0] = 0;
	for (int k = 1; k <= len; k++) {
		for (int i = 0; i < 5; i++) {
			if (pos[k] == i) continue;
			for (int j = 0; j < 5; j++) {
				int C = cost(j, pos[k]);
				dp[k][i][pos[k]] = min(dp[k][i][pos[k]], dp[k - 1][i][j] + C);
			}
		}
		for (int j = 0; j < 5; j++) {
			if (pos[k] == j) continue;
			for (int i = 0; i < 5; i++) {
				int C = cost(i, pos[k]);
				dp[k][pos[k]][j] = min(dp[k][pos[k]][j], dp[k - 1][i][j] + C);
			}
		}
	}
	int res = INF;
	for (int i = 1; i < 5; i++) {
		for (int j = 1; j < 5;  j++) {
			res = min(res, dp[len][i][j]);
		}
	}
	printf("%d\n", res);
	return 0;
}
