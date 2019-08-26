// #1865 웜홀
https://www.acmicpc.net/problem/1865

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
typedef pair <int, int> pii;

int T, N, M, W;
int dist[501];
vector <pii> vc[501];

int main(void) {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		scanf("%d %d %d", &N, &M, &W);
		for (int i = 1; i <= N; i++) {
			dist[i] = INT_MAX;
			vc[i].clear();
		}
		int from, to, val;
		for (int i = 1; i <= M; i++) {
			scanf("%d %d %d", &from, &to, &val);
			vc[from].push_back({ to, val });
			vc[to].push_back({ from, val });
		}
		for (int i = 1; i <= W; i++) {
			scanf("%d %d %d", &from, &to, &val);
			vc[from].push_back({ to, -val });
		}
		bool is_cycle = false;
		dist[1] = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (auto chck : vc[j]) {
					if (dist[j] != INT_MAX && dist[chck.first] > chck.second + dist[j]) {
						if (i == N) 
							is_cycle = true;
						dist[chck.first] = chck.second + dist[j];
					}
				}
			}
		}
		is_cycle ? printf("YES\n") : printf("NO\n");
	}
	return 0;
}
