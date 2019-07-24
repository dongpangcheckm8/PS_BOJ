// #11660 구간 합 구하기 5
https://www.acmicpc.net/problem/11660

#include <stdio.h>
#define MAX_SIZE 1025

int arr[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE];
int n, m;

int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d", &arr[i][j]);
	dp[1][1] = arr[1][1];
	dp[1][2] = dp[1][1] + arr[1][2];
	dp[2][1] = dp[1][1] + arr[2][1];
	for (int i = 2; i <= n; i++) {
		dp[1][i] = dp[1][i - 1] + arr[1][i];
		dp[i][1] = dp[i - 1][1] + arr[i][1];
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		int x1, x2, y1, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n", dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1]);
	}
	return 0;
}
