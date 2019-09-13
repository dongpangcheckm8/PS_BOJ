// #6497 전력난
https://www.acmicpc.net/problem/6497

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

struct ks {
	int from, to, val;
};

int V, E, total;
int parent[200001];
vector <ks> vc;

bool comp(ks a, ks b) { return a.val < b.val; }

int find(int u) {
	if (u == parent[u])
		return u;
	return parent[u] = find(parent[u]);
}

int main(void) {
	while (true) {
		scanf("%d %d", &V, &E);
		if (!V && !E)
			break;
		total = 0;
		vc.clear();
		for (int i = 0; i < V; i++)
			parent[i] = i;
		for (int i = 0; i < E; i++) {
			int from, to, val;
			scanf("%d %d %d", &from, &to, &val);
			vc.push_back({ from, to, val });
			total += val;
		}
		sort(vc.begin(), vc.end(), comp);
		int res = 0;
		for (int i = 0; i < E; i++) {
			int from = find(vc[i].from);
			int to = find(vc[i].to);
			if (from == to)
				continue;
			parent[from] = to;
			res += vc[i].val;
		}
		printf("%d\n", total - res);
	}
	return 0;
}
