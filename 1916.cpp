// #1916 최소비용 구하기
https://www.acmicpc.net/problem/1916

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
#define INF 1000000001;
using namespace std;
typedef pair <int, int> pii;

vector <pii> vc[1001];
int N, M, s, e;

int dijkstra(int s, int e) {
	int dist[1001], visit[1001];
	for (int i = 1; i <= N; i++) {
		dist[i] = INT_MAX;
		visit[i] = 0;
	}
	priority_queue <pii> pq;
	dist[s] = 0;
	pq.push({ 0, s });
	while (!pq.empty()) {
		int here = pq.top().second;
		pq.pop();
		if (visit[here])
			continue;
		visit[here] = 1;
		for (int i = 0; i < vc[here].size(); i++) {
			int there = vc[here].at(i).first;
			int cost = vc[here].at(i).second;
			if (dist[there] > dist[here] + cost) {
				dist[there] = dist[here] + cost;
				pq.push({ -dist[there], there });
			}
		}
	}
	return dist[e];
}

int main(void) {
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 1; i <= M; i++) {
		int from, to, val;
		scanf("%d %d %d", &from, &to, &val);
		vc[from].push_back({ to, val });
	}
	scanf("%d %d", &s, &e);
	printf("%d\n", dijkstra(s, e));
	return 0;
}
