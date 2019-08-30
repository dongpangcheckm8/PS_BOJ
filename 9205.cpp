// #9205 맥주 마시면서 걸어가기
https://www.acmicpc.net/problem/9205

#include <stdio.h>
#include <vector>
#define INF 987654321
using namespace std;

struct st {
	int x, y;
};

int T, N;
int visit[102];
st stores[102];
vector <int> vc[102];

int abs(int a) { return (a >= 0) ? a : -a; }

int dist(st a, st b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

int bfs(void) {
	int wp = 0, rp = 0, out;
	int queue[102 * 102 * 10];
	queue[wp++] = 0;
	visit[0] = 1;
	while (rp < wp) {
		out = queue[rp++];
		if (out == N + 1)
			return 1;
		for (auto there : vc[out]) {
			if (visit[there])
				continue;
			queue[wp++] = there;
			visit[there] = 1;
		}
	}
	return 0;
}

int main(void) {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i = 0; i <= N + 1; i++) {
			visit[i] = 0;
			vc[i].clear();
		}
		scanf("%d %d", &stores[0].x, &stores[0].y);
		for (int i = 1; i <= N; i++) {
			scanf("%d %d", &stores[i].x, &stores[i].y);
		}
		scanf("%d %d", &stores[N + 1].x, &stores[N + 1].y);
		for (int i = 0; i <= N + 1; i++) {
			for (int j = 0; j <= N + 1; j++) {
				if (i == j)
					continue;
				if (dist(stores[i], stores[j]) <= 1000) {
					vc[i].push_back(j);
					vc[j].push_back(i);
				}
					
			}
		}
		if (bfs())
			printf("happy\n");
		else
			printf("sad\n");
	}
	return 0;
}
