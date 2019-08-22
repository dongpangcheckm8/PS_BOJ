// #1504 특정한 최단경로
https://www.acmicpc.net/problem/1504

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;
typedef pair <int, int> pii;

vector <pii> vc[801];
int dist[801];
int N, E, A, B, flag;

int dijkstra(int s, int e) {
	priority_queue <pii> pq;
	int visit[801];
	for (int i = 1; i <= N; i++) {
		dist[i] = INT_MAX;
		visit[i] = 0;
	}
	dist[s] = 0;
	pq.push({ 0, s });
	while (!pq.empty()) {
		int here = pq.top().second;
		pq.pop();
		if (visit[here])
			continue;
		visit[here]++;
		for (auto adj : vc[here]) {
			int there = adj.first;
			int next_cost = adj.second;
			if (dist[there] > dist[here] + next_cost) {
				dist[there] = dist[here] + next_cost;
				pq.push({ -dist[there], there });
			}
		}
	}
	if (dist[e] != INT_MAX)
		return dist[e];
	else {
		flag = 1;
		return -1;
	}
}

int main(void) {
	scanf("%d %d", &N, &E);
	for (int i = 1; i <= E; i++) {
		int from, to, val;
		scanf("%d %d %d", &from, &to, &val);
		vc[from].push_back({ to, val });
		vc[to].push_back({ from, val });
	}
	scanf("%d %d", &A, &B);
	int routeA = 0, routeB = 0, flagA = 0, flagB = 0;
	routeA += dijkstra(1, A);
	routeA += dijkstra(A, B);
	routeA += dijkstra(B, N);
	if (flag)
		flagA = 1;
	flag = 0;
	routeB += dijkstra(1, B);
	routeB += dijkstra(B, A);
	routeB += dijkstra(A, N);
	if (flag)
		flagB = 1;
	int res = 0;
	if (flagA && flagB) {
		printf("-1\n");
		return 0;
	}
	else if (flagA)
		res = routeB;
	else if (flagB)
		res = routeA;
	else
		res = min(routeA, routeB);
	printf("%d\n", res);
	return 0;
}
