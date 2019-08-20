// #1967 트리의 지름
https://www.acmicpc.net/problem/1967

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector <pair <int, int>> vc[100001];
int N, sum, visit[100001];

pair<int, int> bfs(int start) {
	int dist = 0, idx = 0;
	for (int i = 1; i <= N; i++)
		visit[i] = 0;
	queue < pair <int, int> > q;
	q.push({ start, 0 });
	visit[start] = 1;
	while (!q.empty()) {
		pair <int, int> here = q.front();
		q.pop();
		for (int i = 0; i < vc[here.first].size(); i++) {
			pair <int, int> there = vc[here.first].at(i);
			if (visit[there.first])
				continue;
			visit[there.first] = 1;
			if (dist < here.second + there.second) {
				dist = here.second + there.second;
				idx = there.first;
			}
			q.push({there.first, here.second + there.second});
		}
	}
	return { idx, dist };
}

int main(void) {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int from, to, val;
		scanf("%d %d %d", &from, &to, &val);
		vc[from].push_back({ to, val });
		vc[to].push_back({ from, val });
	}
	pair <int, int> start, end;
	start = bfs(1);
	end = bfs(start.first);
	printf("%d\n", end.second);
	return 0;
}
