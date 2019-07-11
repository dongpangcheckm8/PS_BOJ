// #1699. 제곱수의 합
https://www.acmicpc.net/problem/1699

#include <stdio.h>

int n;
const int INF = 10e6;
int dp[101762];

int min(int a, int b) { return (a < b) ? a : b; }

int main(void) {
	scanf("%d", &n);
	int std = 0;
	dp[0] = INF;
	for (int i = 1; i <= n; i++) {
		dp[i] = INF;
		if (i == (std + 1) * (std + 1)) {
			dp[i] = 1;
			std++;
		}

		for (int temp = std; temp > 0; temp--) {
			dp[i] = min(dp[i], min(dp[i - 1] + 1, dp[i - temp * temp] + 1));
		}
	}
	printf("%d\n", dp[n]);
	return 0;
}
