// #1735 분수 합
https://www.acmicpc.net/problem/1735

#include <stdio.h>

int gcd(int n1, int n2) {
	if (n2 % n1 == 0) return n1;
	else gcd(n2 % n1, n1);
}

int main(void) {
	int a_u, a_d, b_u, b_d;
	int gcd_num;
	int result_u, result_d;
	scanf("%d %d", &a_u, &a_d);
	scanf("%d %d", &b_u, &b_d);
	gcd_num = gcd(a_d, b_d);
	result_d = a_d * b_d / gcd_num;
	result_u = result_d / a_d * a_u + result_d / b_d * b_u;
	gcd_num = gcd(result_d, result_u);
	printf("%d %d\n", result_u / gcd_num, result_d / gcd_num);
	return 0;
}
