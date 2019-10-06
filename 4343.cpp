// #4343 Arctic Network
https://www.acmicpc.net/problem/4343

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#define INF 987654321
using namespace std;
typedef pair <int, int> pii;

struct KS {
	int from, to;
	double cost;
	bool operator< (const KS &ref) {
		return ref.cost > cost;
	}
};

struct point {
	int x, y;
};

int N, M;
int parent[501];
bool check;
point arr[501];
vector <KS> edges;

double dist(point a, point b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

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
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &M);
		edges.clear();
		for (int i = 1; i <= M; i++) {
			parent[i] = i;
			scanf("%d %d", &arr[i].x, &arr[i].y);
		}
		for (int i = 1; i < M; i++) {
			for (int j = i + 1; j <= M; j++) {
				edges.push_back({ i, j, dist(arr[i], arr[j]) });
			}
		}
		sort(edges.begin(), edges.end());
		int cnt = M - N;
		for (int i = 0; i < edges.size(); i++) {
			merge(edges[i].from, edges[i].to);
			if (check) {
				cnt--;
				if (!cnt) {
					printf("%.2lf\n", edges[i].cost);
					break;
				}
			}
		}
	}
	return 0;
}
