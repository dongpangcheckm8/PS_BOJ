// #2211 네트워크 복구
https://www.acmicpc.net/problem/2211

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;
typedef pair <int, int> pii;

int N, M;
int dist[1001], parent[1001];
vector <pii> vc[1001];

void dijkstra(void) {
	priority_queue <pii> pq;
	for (int i = 1; i <= N; i++)
		dist[i] = INF;
	pq.push({ 0, 1 });
	dist[1] = 0;
	while (!pq.empty()) {
		int here = pq.top().second;
		int herecost = -pq.top().first;
		pq.pop();
		if (dist[here] < herecost)
			continue;
		for (auto i : vc[here]) {
			int there = i.first;
			int therecost = i.second + herecost;
			if (dist[there] > therecost) {
				dist[there] = therecost;
				pq.push({ -dist[there], there });
				parent[there] = here;
			}
		}
	}
}

int main(void) {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++) {
		int from, to, val;
		scanf("%d %d %d", &from, &to, &val);
		vc[from].push_back({ to, val });
		vc[to].push_back({ from, val });
	}
	dijkstra();
	printf("%d\n", N - 1);
	for (int i = 2; i <= N; i++) {
		printf("%d %d\n", parent[i], i);
	}
	return 0;
}
