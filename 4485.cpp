// #4485 녹색 옷 입은 애가 젤다지?
https://www.acmicpc.net/problem/4485

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;
typedef pair <int, pair <int, int> > piii;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
int arr[125][125], dist[125][125];
int N;

int dijkstra(void) {
	priority_queue <piii> pq;
	int visit[125][125];
	for(int i = 0 ; i < N; i++)
		for (int j = 0; j < N; j++) {
			visit[i][j] = 0;
			dist[i][j] = INT_MAX;
		}
	dist[0][0] = arr[0][0];
	pq.push({ 0, {0, 0} });
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
			if (nextx < 0 || nextx >= N || nexty < 0 || nexty >= N)
				continue;
			if (dist[nextx][nexty] > dist[curx][cury] + arr[nextx][nexty]) {
				dist[nextx][nexty] = dist[curx][cury] + arr[nextx][nexty];
				pq.push({ -dist[nextx][nexty], {nextx, nexty} });
			}
		}
	}
	return dist[N - 1][N - 1];
}

int main(void) {
	int t = 0;
	while (++t) {
		scanf("%d", &N);
		if (N == 0)
			break;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				scanf("%d", &arr[i][j]);
		printf("Problem %d: %d\n", t, dijkstra());
	}
	return 0;
}
