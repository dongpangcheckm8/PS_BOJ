// #1774 우주신과의 교감
https://www.acmicpc.net/problem/1774

#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
#define INF 1000000000
using namespace std;

typedef long long ll;
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

typedef pair <int, int> pii;
int N, M, parent[1001];
bool check;
point arr[1001];
vector <KS> vc;

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

double dist(point a, point b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main(void){
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		scanf("%d %d", &arr[i].x, &arr[i].y);
	}
	for (int i = 1; i <= M; i++) {
		int from, to;
		scanf("%d %d", &from, &to);
		merge(from, to);
	}
	for (int i = 1; i < N; i++) {
		for (int j = i + 1; j <= N; j++) {
			vc.push_back({ i, j, dist(arr[i], arr[j]) });
		}
	}
	sort(vc.begin(), vc.end());
	double res = 0.0;
	for (int i = 0; i < vc.size(); i++) {
		merge(vc[i].from, vc[i].to);
		if (check) {
			res += vc[i].cost;
		}
	}
	printf("%.2lf\n", res);
	return 0;
}
