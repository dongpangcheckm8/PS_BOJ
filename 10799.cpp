// #10799 쇠막대기
https://www.acmicpc.net/problem/10799

#include <stdio.h>

char ps[100001];

int main(void) {
	scanf("%s", ps);
	int idx = 0; int res = 0; int remain = 0;
	bool laser = false;
	while (ps[idx]) {
		if (ps[idx] == '(' && ps[idx + 1] == ')') {
			laser = true;
			res += remain;
			idx++;
		}
		else if (ps[idx] == '(') {
			remain++;
		}
		else if (ps[idx] == ')') {
			if (laser) res++;
			remain--;
		}
		idx++;
	}
	printf("%d\n", res);
	return 0;
}
