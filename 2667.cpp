// #2667 단지번호붙이기
https://www.acmicpc.net/problem/2667

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int N, num;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
int arr[26][26], visit[26][26];
vector <int> vc;

struct st {
	int x, y;
};

int bfs(int x, int y, int num) {
	st queue[26 * 26 * 26 * 5], out;
	int curx = x, cury = y, wp = 0, rp = 0, nextx, nexty;
	visit[curx][cury] = 1;
	arr[curx][cury] = num;
	queue[wp++] = { curx, cury };
	int res = 1;
	while (rp < wp) {
		st out = queue[rp++];
		for (int i = 0; i < 4; i++) {
			nextx = out.x + dx[i];
			nexty = out.y + dy[i];
			if (nextx < 1 || nextx > N || nexty < 1 || nexty > N || arr[nextx][nexty] != 1 || visit[nextx][nexty])
				continue;
			visit[nextx][nexty] = 1;
			arr[nextx][nexty] = num;
			queue[wp++] = { nextx, nexty };
			res++;
		}
	}
	return res;
}

int main(void) {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%1d", &arr[i][j]);
	num = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visit[i][j] && arr[i][j]) {
				vc.push_back(bfs(i, j, ++num));
			}
		}
	}
	printf("%d\n", num - 1);
	sort(vc.begin(), vc.end());
	for (int i = 0; i < vc.size(); i++)
		printf("%d\n", vc[i]);
	return 0;
}
