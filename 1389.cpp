// #1389 케빈 베이컨의 6단계 법칙
https://www.acmicpc.net/problem/1389

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector <int> vc[101];
int ans[101], arr[101][101];

void bfs(int V) {
	int visit[101];
	queue <pair <int, int>> q;
	for (int i = 1; i <= N; i++)
		visit[i] = 0;
	visit[V] = 1;
	q.push({V, 0});
	int std = 0;
	while (!q.empty()) {
		int here = q.front().first; 
		int cost = q.front().second;
		q.pop();
		cost++;
		for (int i = 0; i < vc[here].size(); i++) {
			int there = vc[here][i];
			if (visit[there])
				continue;
			visit[there] = 1;
			ans[V] += cost;
			q.push({ there, cost });
		}
	}
}

int main(void) {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++) {
		int from, to;
		scanf("%d %d", &from, &to);
		vc[from].push_back(to);
		vc[to].push_back(from);
	}
	for (int i = 1; i <= N; i++)
		bfs(i);
	int res = 987654321;
	int idx = 0;
	for (int i = 1; i <= N; i++) {
		if (res > ans[i]) {
			res = ans[i];
			idx = i;
		}
	}
	printf("%d\n", idx);
	return 0;
}
