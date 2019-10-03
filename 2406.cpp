// #2406 (안정적인 네트워크)
https://www.acmicpc.net/problem/2406

#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;
typedef pair <int, int> pii;

struct KS {
	int from, to, cost;
	bool operator< (const KS &ref) {
		return ref.cost > cost;
	}
};

int N, M;
int parent[1001];
bool check;
vector <int> vc[1001];
vector <KS> edges;
vector <pii> ans;

int find(int u) {
	if (u == parent[u])
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
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
		parent[i] = i;
	for (int i = 1; i <= M; i++) {
		int from, to;
		scanf("%d %d", &from, &to);
		merge(from, to);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int cost;
			scanf("%d", &cost);
			edges.push_back({ i, j, cost });
		}
	}
	sort(edges.begin(), edges.end());
	int res = 0;
	for (int i = 0; i < edges.size(); i++) {
		if (edges[i].from != 1 && edges[i].to != 1) {
			merge(edges[i].from, edges[i].to);
			if (check) {
				res += edges[i].cost;
				ans.push_back({ edges[i].from, edges[i].to });
			}
		}
	}
	printf("%d %d\n", res, ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}
