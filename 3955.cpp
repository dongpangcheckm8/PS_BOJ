// #3955 캔디 분배
https://www.acmicpc.net/problem/3955

#include <stdio.h>
#include <vector>
using namespace std;

struct info {
	int gcd;
	int s;
	int t;
};
vector <int> s, t, r, q;

info xGCD(int a, int b) {
	s = { 1, 0 };
	t = { 0, 1 };
	r = { a, b };
	while (true) {
		int r2 = r[r.size() - 2];
		int r1 = r[r.size() - 1];
		q.push_back(r2 / r1);
		r.push_back(r2 % r1);

		if (r[r.size() - 1] == 0) {
			break;
		}

		int s2 = s[s.size() - 2];
		int s1 = s[s.size() - 1];
		int t2 = t[t.size() - 2];
		int t1 = t[t.size() - 1];
		int q1 = q[q.size() - 1];
		s.push_back(s2 - s1 * q1);
		t.push_back(t2 - t1 * q1);
	}

	info ret = { r[r.size() - 2], s[s.size() - 1], t[t.size() - 1] };
	s.clear(), t.clear(), r.clear(), q.clear();
	return ret;
}

int main(void) {
	int K, C, t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d %d", &K, &C);
		if (C == 1) {
			if (K == 1000000000) printf("IMPOSSIBLE\n");
			else printf("%d\n", (K + 1) / C);
			continue;
		}
		else if (K == 1) {
			printf("1\n");
			continue;
		}
		info ret = xGCD(K, C);
		if (ret.gcd == 1) {
			printf("%d\n", ret.t < 0 ? ret.t + K : ret.t);
		}
		else {
			printf("IMPOSSIBLE\n");
		}
	}
	return 0;
}
