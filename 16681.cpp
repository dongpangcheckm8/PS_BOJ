// #16681 등산
https://www.acmicpc.net/problem/16681

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1000000000000
typedef long long ll;
using namespace std;

typedef pair <int, int> pii;

int N, M, D, E;
int height[100001];
ll dist[100001][2];
vector <pii> vc[100001];

ll max(ll a, ll b) { return (a > b) ? a : b; }

void dijkstra(int start, int flag) {
	int visit[100001];
	for (int i = 1; i <= N; i++) {
		visit[i] = 0;
		dist[i][flag] = INF;
	}
	priority_queue <pair <ll, int>> pq;
	dist[start][flag] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int here = pq.top().second;
		ll hereCost = -pq.top().first;
		pq.pop();
		if (visit[here])
			continue;
		visit[here] = 1;
		for (int i = 0; i < vc[here].size(); i++) {
			int there = vc[here][i].first;
			int thereCost = vc[here][i].second;
			if (height[there] > height[here] && dist[there][flag] > dist[here][flag] + thereCost) {
				dist[there][flag] = dist[here][flag] + thereCost;
				pq.push({ -dist[there][flag], there });
			}
		}
	}
}

int main(void) {
	scanf("%d %d %d %d", &N, &M, &D, &E);
	for (int i = 1; i <= N; i++)
		scanf("%d", &height[i]);
	for (int i = 1; i <= M; i++) {
		int from, to, val;
		scanf("%d %d %d", &from, &to, &val);
		vc[from].push_back({ to, val });
		vc[to].push_back({ from, val });
	}
	ll res = -INF;
	dijkstra(1, 0);
	dijkstra(N, 1);
	for (int i = 2; i < N; i++) {
		if (dist[i][0] == INF || dist[i][1] == INF)
			continue;
		res = max(res, (ll)height[i] * E - (dist[i][0] + dist[i][1]) * D);
	}
	if (res != -INF)
		printf("%lld\n", res);
	else
		printf("Impossible\n");
	return 0;
}
