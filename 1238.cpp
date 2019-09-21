// #1238 파티
https://www.acmicpc.net/problem/1238

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

typedef pair <int, int> pii;

int N, M, X;
int dist[1001][1001];
vector <pii> vc[1001];

void dijkstra(int S, int E) {
	int visit[1001];
	for (int i = 1; i <= N; i++) {
		visit[i] = 0;
		dist[S][i] = INF;
	}
	priority_queue <pii> pq;
	dist[S][S] = 0;
	pq.push({ 0, S });
	while (!pq.empty()) {
		int here = pq.top().second;
		int hereCost = -pq.top().first;
		pq.pop();
		if (here == E)
			break;
		if (visit[here])
			continue;
		visit[here] = 1;
		for (int i = 0; i < vc[here].size(); i++) {
			int there = vc[here][i].first;
			int thereCost = vc[here][i].second;
			if (dist[S][there] > dist[S][here] + thereCost) {
				dist[S][there] = dist[S][here] + thereCost;
				pq.push({ -dist[S][there], there });
			}
		}
	}
}

int main(void) {
	scanf("%d %d %d", &N, &M, &X);
	for (int i = 1; i <= M; i++) {
		int from, to, val;
		scanf("%d %d %d", &from, &to, &val);
		vc[from].push_back({ to, val });
	}
	int res = 0;
	for (int i = 1; i <= N; i++) {
		dijkstra(i, X);
		dijkstra(X, i);
		res = max(res, dist[i][X] + dist[X][i]);
	}
	printf("%d\n", res);
	return 0;
}
