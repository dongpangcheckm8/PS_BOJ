// #1647 도시 분할 계획
https://www.acmicpc.net/problem/1647

#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct KS {
	int from, to, val;
};
int V, E;
int parent[100001];
bool check;
vector <KS> vc;

bool comp(const KS &a, const KS &b) { return a.val < b.val; }

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
	scanf("%d %d", &V, &E);
	for (int i = 1; i <= V; i++)
		parent[i] = i;
	for (int i = 1; i <= E; i++) {
		KS ks;
		scanf("%d %d %d", &ks.from, &ks.to, &ks.val);
		vc.push_back(ks);
	}
	sort(vc.begin(), vc.end(), comp);
	int cnt = 0, res = 0;
	for (int i = 0; i < E; i++) {
		merge(vc[i].from, vc[i].to);
		if (check) {
			res += vc[i].val;
			cnt++;
		}
		if (cnt == (V - 2))
			break;
	}
	printf("%d\n", res);
	return 0;
}
