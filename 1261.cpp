// #1261 알고스팟
https://www.acmicpc.net/problem/1261

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;
typedef pair <int, pair <int, int> > piii;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
int arr[101][101], dist[101][101], visit[101][101];
int N, M;

int dijkstra(void) {
	priority_queue <piii> pq;
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++)
			dist[i][j] = INT_MAX;
	dist[1][1] = 0;
	pq.push({ 0, {1, 1} });
	while (!pq.empty()) {
		int curx = pq.top().second.first;
		int cury = pq.top().second.second;
		pq.pop();
		if (visit[curx][cury])
			continue;
		visit[curx][cury]++;
		for (int i = 0; i < 4; i++) {
			int nextx = curx + dx[i];
			int nexty = cury + dy[i];
			if (nextx < 1 || nextx > M || nexty < 1 || nexty > N)
				continue;
			if (dist[nextx][nexty] > dist[curx][cury] + arr[nextx][nexty]) {
				dist[nextx][nexty] = dist[curx][cury] + arr[nextx][nexty];
				pq.push({ -dist[nextx][nexty], {nextx, nexty} });
			}
		}
	}
	return dist[M][N];
}

int main(void) {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++)
			scanf("%1d", &arr[i][j]);
	printf("%d\n", dijkstra());
	return 0;
}
