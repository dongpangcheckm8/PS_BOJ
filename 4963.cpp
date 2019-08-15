// #4963 섬의 개수
https://www.acmicpc.net/problem/4963

#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;

int W, H, num;
int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int arr[51][51], visit[51][51];

struct st {
	int x, y;
};

void bfs(int x, int y, int num) {
	st queue[51 * 51 * 10], out;
	int curx = x, cury = y, wp = 0, rp = 0, nextx, nexty;
	visit[curx][cury] = 1;
	arr[curx][cury] = num;
	queue[wp++] = { curx, cury };
	while (rp < wp) {
		out = queue[rp++];
		for (int i = 0; i < 8; i++) {
			nextx = out.x + dx[i];
			nexty = out.y + dy[i];
			if (nextx < 1 || nextx > H || nexty < 1 || nexty > W || arr[nextx][nexty] != 1 || visit[nextx][nexty])
				continue;
			visit[nextx][nexty] = 1;
			arr[nextx][nexty] = num;
			queue[wp++] = { nextx, nexty };
		}
	}
}

int main(void) {
	for (;;) {
		scanf("%d %d", &W, &H);
		memset(visit, 0, sizeof(visit));
		if (W == 0 && H == 0)
			break;
		for (int i = 1; i <= H; i++)
			for (int j = 1; j <= W; j++)
				scanf("%d", &arr[i][j]);
		num = 1;
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				if (!visit[i][j] && arr[i][j]) {
					bfs(i, j, ++num);
				}
			}
		}
		printf("%d\n", num - 1);
	}
	return 0;
}
