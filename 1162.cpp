// #1162 도로포장
https://www.acmicpc.net/problem/1162

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
typedef long long ll;
using namespace std;

typedef pair <int, int> pii;

int N, M, K;
ll dist[10001][21];
vector <pii> vc[10001];

ll min(ll a, ll b) { return (a < b) ? a : b; }

void dijkstra(int start, int left) {
	int visit[10001][21];
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			visit[i][j] = 0;
			dist[i][j] = LLONG_MAX;
		}
	}
	priority_queue <pair <pair <ll, int>, int>> pq;
	dist[start][left] = 0;
	pq.push({{ 0, start }, left});
	while (!pq.empty()) {
		int here = pq.top().first.second;
		ll hereCost = -pq.top().first.first;
		int lefts = pq.top().second;
		//printf("here : %d, hereCost : %lld, lefts : %d\n", here, hereCost, lefts);
		pq.pop();
		if (here == N)
			break;
		if (visit[here][lefts])
			continue;
		visit[here][lefts] = 1;
		for (int i = 0; i < vc[here].size(); i++) {
			int there = vc[here][i].first;
			int thereCost = vc[here][i].second;
			if (lefts) {
				if (dist[there][lefts] > dist[here][lefts] + thereCost) {
					dist[there][lefts] = dist[here][lefts] + thereCost;
					pq.push({ {-dist[there][lefts], there}, lefts });
				}
				if (dist[there][lefts - 1] > dist[here][lefts]) {
					dist[there][lefts - 1] = dist[here][lefts];
					pq.push({ {-dist[there][lefts - 1], there}, lefts - 1 });
				}
			}
			else {
				if (dist[there][lefts] > dist[here][lefts] + thereCost) {
					dist[there][lefts] = dist[here][lefts] + thereCost;
					pq.push({ {-dist[there][lefts], there}, lefts });
				}
			}
		}
	}
}

int main(void) {
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= M; i++) {
		int from, to, val;
		scanf("%d %d %d", &from, &to, &val);
		vc[from].push_back({ to, val });
		vc[to].push_back({ from, val });
	}
	dijkstra(1, K);
	ll res = LLONG_MAX;
	for (int i = 0; i <= K; i++) {
		//printf("dist[%d][%d] : %lld\n", N, dist[N][i]);
		res = min(res, dist[N][i]);
	}
	printf("%lld\n", res);
	return 0;
}
