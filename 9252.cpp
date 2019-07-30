// #9252 LCS 2
https://www.acmicpc.net/problem/9252

#include <stdio.h>

char S1[1003], S2[1003], ANS[1003];
int dp[1002][1002];
int ANS_IDX = 1;

int max(int a, int b) { return (a > b) ? a : b; }
int strlen(char str[]) {
	int len = 1;
	for (; str[len]; len++);
	return len - 1;
}

void make_LCS(void) {
	for (int i = 1; S2[i]; i++) {
		for (int j = 1; S1[j]; j++) {
			if (S2[i] == S1[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
}

void find_word(void) {
	int S1_len = strlen(S1);
	int S2_len = strlen(S2);
	int num = dp[S2_len][S1_len];
	
	printf("%d\n", num);
	while (num > 0) {
		num = dp[S2_len][S1_len];
		if (num == dp[S2_len][S1_len - 1])
			S1_len--;
		else if (num == dp[S2_len - 1][S1_len])
			S2_len--;
		else if(num - 1 == dp[S2_len - 1][S1_len - 1]) {
			ANS[ANS_IDX++] = S1[S1_len];
			S1_len--;
			S2_len--;
		}
	}
}

int main(void) {
	scanf("%s", S1 + 1);
	scanf("%s", S2 + 1);
	make_LCS();
	find_word();
	for (int i = ANS_IDX - 1; i >= 1; i--)
		printf("%c", ANS[i]);
	return 0;
}
