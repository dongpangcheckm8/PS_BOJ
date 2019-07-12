// #11052 카드 구매하기
https://www.acmicpc.net/problem/11052

#include <stdio.h>

int n;
int p[1001];
int dp[1001];

int max(int a, int b) { return (a > b) ? a : b; }

int sol(int n) {
	if (n == 0) return 0;
	int& ret = dp[n];
	if (ret != -1) return ret;
	ret = p[n];
	for (int i = 1; i <= n; i++) {
		ret = max(ret, sol(n - i) + p[i]);
	}
	
	return ret;
}

int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
		dp[i] = -1;
	}
	dp[0] = -1;
	printf("%d\n", sol(n));
	return 0;
}
