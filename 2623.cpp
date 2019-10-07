// #2623 음악프로그램
https://www.acmicpc.net/problem/2623

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int N, M, indegree[1001];
vector <int> vc[1001];
queue <int> q;

int main(void) {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; i++) {
		int K, prev, curr;
		scanf("%d", &K);
		if (!K)
			continue;
		scanf("%d", &prev);
		for (int j = 1; j < K; j++) {
			scanf("%d", &curr);
			indegree[curr]++;
			vc[prev].push_back(curr);
			prev = curr;
		}
	}
	int ans[1001];
	for (int i = 1; i <= N; i++) {
		if (!indegree[i])
			q.push(i);
	}
	for (int i = 1; i <= N; i++) {
		if (q.empty()) {
			puts("0");
			return 0;
		}
		int curr = q.front();
		q.pop();
		ans[i] = curr;
		for (int next : vc[curr]) {
			if (--indegree[next] == 0)
				q.push(next);
		}
	}
	for (int i = 1; i <= N; i++)
		printf("%d\n", ans[i]);
	return 0;
}
