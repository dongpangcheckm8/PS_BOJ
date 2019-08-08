// #1102 #발전소
https://www.acmicpc.net/problem/1102


#include <stdio.h>
#include <cstring>
#define INF 987654321

int arr[16][16], status[16];
int dp[16][1 << 16];
int N, P, statusBit;

int min(int a, int b) { return (a < b) ? a : b; }

int bit_count(int num) {
	int cnt = 0;
	while (num) {
		cnt += (num & 1);
		num >>= 1;
	}
	return cnt;
}

int sol(int here, int statusBit) {
	int& ret = dp[here][statusBit];
	if (ret != -1)
		return ret;
	if (bit_count(statusBit) >= P) {
		return 0;
	}
	ret = INF;
	for (int i = 0; i < N; i++) {
		if ((statusBit & (1 << i)) == 0) {
			int nextBit = statusBit | (1 << i);
			for (int j = 0; j < N; j++) {
				if (nextBit & (1 << j))
					ret = min(ret, arr[here][i] + sol(j, nextBit));
			}
		}
	}
	return ret;
}

int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &arr[i][j]);
	char st[17];
	scanf("%s", st);
	for (int i = 0; i < N; i++) {
		if (st[i] == 'Y') {
			status[i] = 1;
			statusBit |= (1 << i);
		}
		else
			status[i] = 0;
	}
	scanf("%d", &P);
	if (!P) {
		printf("0\n");
		return 0;
	}
	memset(dp, -1, sizeof(dp));
	int res = INF;
	for (int i = 0; i < N; i++) {
		if(status[i])
			res = min(res, sol(i, statusBit));
	}
	if (res == INF)
		printf("-1\n");
	else printf("%d\n", res);
	return 0;
}
