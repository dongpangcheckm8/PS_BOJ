// #1761 정점들의 거리
https://www.acmicpc.net/problem/1761

#include <stdio.h>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 16
using namespace std;

typedef pair <int, int> pii;
typedef long long ll;

int N, M;
int depth[40001], parent[40001][MAX];
ll dist[40001];
vector <pii> vc[40001];

void makeTree(int curr) {
	for (auto next : vc[curr]) {
		int there = next.first;
		if (depth[there] == -1) {
			dist[there] = dist[curr] + next.second;
			parent[there][0] = curr;
			depth[there] = depth[curr] + 1;
			makeTree(there);
		}
	}
}

int main(void) {
	scanf("%d", &N);
	memset(parent, -1, sizeof(parent));
	memset(depth, -1, sizeof(depth));
	depth[1] = 0;
	for (int i = 1; i < N; i++) {
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		vc[from].push_back({ to, cost });
		vc[to].push_back({ from, cost });
	}
	dist[1] = 0;
	makeTree(1);
	for (int j = 0; j < MAX - 1; j++) {
		for (int i = 1; i <= N; i++) {
			if (parent[i][j] != -1) {
				parent[i][j + 1] = parent[parent[i][j]][j];
			}
		}
	}
	scanf("%d", &M);
	for (int i = 1; i <= M; i++) {
		int from, to;
		scanf("%d %d", &from, &to);
		int u = from, v = to;
		if (depth[u] < depth[v])
			swap(u, v);
		int diff = depth[u] - depth[v];
		for (int j = 0; diff; j++) {
			if (diff % 2)
				u = parent[u][j];
			diff /= 2;
		}
		if (u != v) {
			for (int j = MAX - 1; j >= 0; j--) {
				if (parent[u][j] != -1 && parent[u][j] != parent[v][j]) {
					u = parent[u][j];
					v = parent[v][j];
				}
			}
			u = parent[u][0];
		}
		printf("%lld\n", dist[from] + dist[to] - 2 * dist[u]);
	}
	return 0;
}
