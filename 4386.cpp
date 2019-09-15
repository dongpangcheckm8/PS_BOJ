// #4386 별자리 만들기
https://www.acmicpc.net/problem/4386

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

struct INFO {
	double x, y;
};

struct KS {
	int from, to;
	double val;
};
int V;
int parent[100001];
bool check;
INFO info[101];
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
	scanf("%d", &V);
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
		scanf("%lf %lf", &info[i].x, &info[i].y);
	}
	for (int i = 1; i < V; i++) {
		for (int j = i + 1; j <= V; j++) {
			double x1 = info[i].x;
			double x2 = info[j].x;
			double y1 = info[i].y;
			double y2 = info[j].y;
			double cost = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
			vc.push_back({ i, j, cost });
		}
	}
	sort(vc.begin(), vc.end(), comp);
	double res = 0;
	int cnt = 0;
	for (int i = 0; i < vc.size(); i++) {
		merge(vc[i].from, vc[i].to);
		if (check) {
			res += vc[i].val;
			cnt++;
		}
		if (cnt == V - 1)
			break;
	}
	printf("%.2lf\n", res);
	return 0;
}
