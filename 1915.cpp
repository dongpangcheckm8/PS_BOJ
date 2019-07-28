// #1915 가장 큰 정사각형
https://www.acmicpc.net/problem/1915

#include <stdio.h>
#define MAX_SIZE 1001

int map[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE];

int min(int a, int b) { return (a < b) ? a : b; }

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &map[i][j]);
			if (map[i][j]) res = 1;
		}
	}
	for (int i = 1; i <= n; i++)
		dp[i][1] = map[i][1];
	for (int i = 1; i <= m; i++)
		dp[1][i] = map[1][i];
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			if (map[i][j] == 1) {
				if (!dp[i - 1][j] || !dp[i][j - 1]) dp[i][j] = 1;
				else {
					if (dp[i - 1][j] != dp[i][j - 1]) {
						dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
						if (res < dp[i][j]) res = dp[i][j];
					}
					else {
						if (dp[i - dp[i - 1][j]][j - dp[i - 1][j]]) {
							dp[i][j] = dp[i - 1][j] + 1;
							if (res < dp[i][j]) res = dp[i][j];
						}
						else
							dp[i][j] = dp[i - 1][j];
					}
				}
			}
		}
	}
	printf("%d\n", res * res);
	return 0;
}
