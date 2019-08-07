// #1707 이분 그래프
https://www.acmicpc.net/problem/1707


#include <stdio.h>
#include <vector>
using namespace std;

vector <int> vc[20001];
int V, E;
int visit[20001], color[20001];
bool isBipartite;

void dfs(int V, int clr) {
	if (visit[V]) {
		if (color[V] != clr) {
			isBipartite = false;
		}
		return;
	}
	else {
		visit[V] = 1;
		color[V] = clr;
	}
	for (int i : vc[V]) {
		dfs(i, !clr);
	}
}

int main(void) {
	int K;
	scanf("%d", &K);
	for (int tc = 1; tc <= K; tc++) {
		scanf("%d %d", &V, &E);
		for (int i = 1; i <= V; i++) {
			visit[i] = 0;
			vc[i].clear();
		}
		for (int i = 1; i <= E; i++) {
			int from, to;
			scanf("%d %d", &from, &to);
			vc[from].push_back(to);
			vc[to].push_back(from);
		}
		for (int i = 1; i <= V; i++) {
			color[i] = -1;
		}
		int res = 0;
		isBipartite = true;
		for (int i = 3; i <= V; i++) {
			if (!visit[i]) {
				dfs(i, 0);
			}
		}
		printf("%s\n", isBipartite ? "YES" : "NO");
	}
	return 0;
}
