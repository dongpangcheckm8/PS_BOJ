// #2842 집배원 한상덕
https://www.acmicpc.net/problem/2842

#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;

char arr[51][51];
int height[51][51], range[51 * 51], visit[51][51];
int dr[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int N, K;
int startx, starty;

struct st {
	int r, c;
};

int max(int a, int b) { return (a > b) ? a : b; }
int min(int a, int b) { return (a < b) ? a : b; }

int dfs(int x, int y, int mn, int mx) {
	if (visit[y][x] || height[y][x] < mn || height[y][x] > mx ||
		x < 1 || x > N || y < 1 || y > N)
		return 0;
	visit[y][x] = 1;
	int ret = 0;
	if (arr[y][x] == 'K')
		ret++;
	for (int i = 0; i < 8; i++) {
		int nx = x + dc[i];
		int ny = y + dr[i];
		ret += dfs(nx, ny, mn, mx);
	}
	return ret;
}

int main(void) {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf(" %c", &arr[i][j]);
			if (arr[i][j] == 'P') {
				starty = i;
				startx = j;
			}
			else if (arr[i][j] == 'K')
				K++;
		}
	}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			scanf("%d", &height[i][j]);
			range[(i - 1) * N + j] = height[i][j];
		}
	sort(range + 1, range + (N * N));
	int j = 1, ans = 1000001;
	for (int i = 1; i <= N * N; i++) {
		while (1) {
			memset(visit, 0, sizeof(visit));
			if (dfs(startx, starty, range[j], range[i]) != K)
				break;
			ans = min(ans, range[i] - range[j]);
			j++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
