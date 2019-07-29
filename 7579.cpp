// #7579 앱
https://www.acmicpc.net/problem/7579

#include<stdio.h>

int arr[101], cost[101], dp[10001][101];
int N, M;

int max(int a, int b) { return (a > b) ? a : b; }

int get_ans(int C, int idx) {
	if (idx == N + 1) return 0;
	int& ret = dp[C][idx];
	if (ret != -1) return ret;
	if (C < cost[idx])
		return ret = get_ans(C, idx + 1);
	else {
		return ret = max(get_ans(C - cost[idx], idx + 1) + arr[idx], get_ans(C, idx + 1));
	}
}

int main(void) {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);
	for (int i = 1; i <= N; i++)
		scanf("%d", &cost[i]);
	for (int i = 1; i <= 10000; i++)
		for (int j = 1; j <= 100; j++)
			dp[i][j] = -1;
	for (int i = 1; i <= 10000; i++){
		if (get_ans(i, 1) >= M) {
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}
