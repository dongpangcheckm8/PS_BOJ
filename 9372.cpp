// #9372 상근이의 여행
https://www.acmicpc.net/problem/9372

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct KS {
	int from, to;
};

int N, M;
int parent[1001];
vector <KS> vc;
bool check;

int find(int u) {
	if (parent[u] == u)
		return u;
	return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
	check = false;
	u = find(u);
	v = find(v);
	if (u == v)
		return;
	parent[u] = v;
	check = true;
}

int main(void) {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &M);
		for (int i = 1; i <= N; i++) {
			parent[i] = i;
			vc.clear();
		}
		for (int i = 1; i <= M; i++) {
			int from, to;
			scanf("%d %d", &from, &to);
			vc.push_back({ from, to });
			vc.push_back({ to, from });
		}
		int res = 0;
		for (int i = 0; i < vc.size(); i++) {
			merge(vc[i].from, vc[i].to);
			if (check) {
				res++;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
