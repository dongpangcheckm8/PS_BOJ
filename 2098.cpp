// #2098 외판원 순회
https://www.acmicpc.net/problem/2098

#include <stdio.h>
#include <cstring>
#define INF 987654321

int arr[16][16];
int dp[16][1 << 16];
int N;

int min(int a, int b) { return (a < b) ? a : b; }

int TSP(int here, int bitmask) {
	int& ret = dp[here][bitmask];
	if (ret != -1)
		return ret;

	if (bitmask == (1 << N) - 1) {
		if (arr[here][0] == 0)
			return ret = INF;
		return ret = arr[here][0];
	}

	ret = INF;
	for (int i = 0; i < N; i++) {
		if (bitmask & (1 << i) || !arr[here][i])
			continue;
		ret = min(ret, TSP(i, bitmask | (1 << i)) + arr[here][i]);
	}
	return ret;
}

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &arr[i][j]);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", TSP(0, 1 << 0));
	return 0;
}
