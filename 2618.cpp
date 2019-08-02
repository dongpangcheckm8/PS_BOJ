// #2618 경찰차
https://www.acmicpc.net/problem/2618

#include <stdio.h>
#include <cstring>

struct point {
	int x, y;
};

point P[1001];
int N, W, arr[1001][1001], dp[1001][1001], ans[1001];

int max(int a, int b) { return (a > b) ? a : b; }
int min(int a, int b) { return (a < b) ? a : b; }
int abs(int a) { return (a >= 0) ? a : -a; }
int dis(point p1, point p2) { return (abs(p1.x - p2.x) + abs(p1.y - p2.y)); }

int func(int x, int y) {
	int& ret = dp[x][y];
	if (ret != -1)
		return ret;
	if (x == W || y == W)
		return 0;
	int fir, sec;
	if (x == 0) {
		fir = func(max(x, y) + 1, y) + dis(P[max(x, y) + 1], { 1, 1 });
	}
	else {
		fir = func(max(x, y) + 1, y) + dis(P[max(x, y) + 1], P[x]);
	}
	if (y == 0) {
		sec = func(x, max(x, y) + 1) + dis(P[max(x, y) + 1], { N, N });
	}
	else {
		sec = func(x, max(x, y) + 1) + dis(P[max(x, y) + 1], P[y]);
	}
	return ret = min(fir, sec);
}

void sol(int x, int y) {
	if (x == W || y == W)
		return;
	int fir, sec;
	if (x == 0) {
		fir = func(max(x, y) + 1, y) + dis(P[max(x, y) + 1], { 1, 1 });
	}
	else {
		fir = func(max(x, y) + 1, y) + dis(P[max(x, y) + 1], P[x]);
	}
	if (y == 0) {
		sec = func(x, max(x, y) + 1) + dis(P[max(x, y) + 1], { N, N });
	}
	else {
		sec = func(x, max(x, y) + 1) + dis(P[max(x, y) + 1], P[y]);
	}
	if (fir < sec) {
		ans[max(x, y) + 1] = 1;
		sol(max(x, y) + 1, y);
	}
	else {
		ans[max(x, y) + 1] = 2;
		sol(x, max(x, y) + 1);
	}
}

int main(void) {
	scanf("%d", &N);
	scanf("%d", &W);
	for (int i = 1; i <= W; i++)
		scanf("%d %d", &P[i].x, &P[i].y);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", func(0, 0));
	sol(0, 0);
	for (int i = 1; i <= W; i++)
		printf("%d\n", ans[i]);
	return 0;
}
