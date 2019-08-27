// #1219 오민식의 고민
https://www.acmicpc.net/problem/1219

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
using namespace std;
typedef long long ll;
typedef pair <int, ll> pil;

int N, M, A, B, flag;
ll dist[100], price[100];
vector <pil> vc[100];

void can_arrive(int v) {
	int out;
	int visit[100];
	queue <int> q;
	for (int i = 0; i < N; i++)
		visit[i] = 0;
	visit[v] = 1;
	q.push(v);
	while (!q.empty()) {
		out = q.front();
		if (out == B) {
			flag = 1;
			break;
		}
		q.pop();
		for (auto there : vc[out]) {
			if (visit[there.first])
				continue;
			visit[there.first] = 1;
			q.push(there.first);
		}
	}
}

int main(void) {
	scanf("%d %d %d %d", &N, &A, &B, &M);
	for (int i = 1; i <= M; i++) {
		int from, to;
		ll val;
		scanf("%d %d %lld", &from, &to, &val);
		vc[from].push_back({ to, -val });
	}
	for (int i = 0; i < N; i++) {
		scanf("%lld", &price[i]);
		dist[i] = -LLONG_MAX;
	}
	bool cycle = false;
	dist[A] = price[A];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (flag)
				break;
			for (auto check : vc[j]) {
				if (dist[j] != -LLONG_MAX && dist[check.first] < dist[j] + check.second + price[check.first]) {
					dist[check.first] = dist[j] + check.second + price[check.first];
					if (i == N - 1) {
						can_arrive(j);
						if(flag)
							cycle = true;
					}
				}
			}
		}
	}
	if (dist[B] == -LLONG_MAX)
		printf("gg\n");
	else if (cycle)
		printf("Gee\n");
	else
		printf("%lld\n", dist[B]);
	return 0;
}
