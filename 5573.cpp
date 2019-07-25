// #5573 산책
https://www.acmicpc.net/problem/5573

#include <stdio.h>
#define MAX_SIZE 1005

int arr[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE];
int w, h, n;

int main(void) {
	scanf("%d %d %d", &h, &w, &n);
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			scanf("%d", &arr[i][j]);
	dp[1][1] = n;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (arr[i][j] == 0) {
				dp[i + 1][j] += (dp[i][j] + 1) / 2;
				dp[i][j + 1] += dp[i][j] / 2;
			}
			else {
				dp[i + 1][j] += dp[i][j] / 2;
				dp[i][j + 1] += (dp[i][j] + 1) / 2;
			}
		}
	}
	int x = 1, y = 1;
	while (x <= h && y <= w) {
		int dir = dp[x][y];
		if (dir % 2 == 0) {
			if (arr[x][y] == 0) y++;
			else x++;
		}
		else {
			if (arr[x][y] == 0) x++;
			else y++;
		}
	}
	printf("%d %d\n", x, y);
	return 0;
}
