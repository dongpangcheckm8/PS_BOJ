// #9373 복도 뚫기
https://www.acmicpc.net/problem/9373

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

typedef long long ll;

struct st {
	int x, y, r, idx;
};

struct ks {
	int from, to;
	double val;
};

int N, W, parent[1002];
st sensor[1002];
bool check;

int compx(const st &a, const st &b) {
	return a.x < b.x;
}

int compVC(const ks &a, const ks &b) {
	return a.val < b.val;
}

double length(int x1, int x2, int y1, int y2) {
	return sqrt((ll)(x1 - x2) * (x1 - x2) + (ll)(y1 - y2) * (y1 - y2));
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
		scanf("%d", &W);
		scanf("%d", &N);
		memset(sensor, 0, sizeof(sensor));
		for (int i = 0; i <= N + 1; i++)
			parent[i] = i;
		for (int i = 1; i <= N; i++) {
			scanf("%d %d %d", &sensor[i].x, &sensor[i].y, &sensor[i].r);
		}
		sensor[0].x = 0;
		sensor[N + 1].x = W;
		sort(sensor + 1, sensor + N + 1, compx);
		for (int i = 0; i <= N + 1; i++)
			sensor[i].idx = i;
		vector <ks> vc;
		vc.push_back(ks{ sensor[N + 1].idx, sensor[0].idx, (double)W });
		for (int i = 1; i <= N; i++) {
			int x = sensor[i].x;
			int r = sensor[i].r;
			double len = max(0, x - r);
			vc.push_back(ks{ sensor[i].idx, sensor[0].idx, len });
			len = max(0, W - x - r);
			vc.push_back(ks{ sensor[N + 1].idx, sensor[i].idx, len });
		}

		for (int j = 1; j < N; j++) {
			for (int k = j + 1; k <= N; k++) {
				int x1 = sensor[j].x;
				int y1 = sensor[j].y;
				int x2 = sensor[k].x;
				int y2 = sensor[k].y;
				double len = length(x1, x2, y1, y2);
				vc.push_back(ks{ sensor[k].idx, sensor[j].idx, max((double)0.0, len - (double)sensor[j].r - (double)sensor[k].r) });
			}
		}
		sort(vc.begin(), vc.end(), compVC);
		for (int i = 0; i < vc.size(); i++) {
			merge(vc[i].from, vc[i].to);
			if (check == true) {
				if (find(0) == find(N + 1)) {
					if (vc[i].val == 0)
						printf("0\n");
					else
						printf("%.6lf\n", vc[i].val / 2);
					break;
				}
			}
		}
	}
	return 0;
}
