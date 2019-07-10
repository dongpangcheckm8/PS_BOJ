// #11054 가장 긴 바이토닉 부분 수열
https://www.acmicpc.net/problem/11054

#include <stdio.h>

int n;
int arr[1001];
int dp[2][1001];

int max(int a, int b){return (a > b) ? a : b;}

int main(void){
	scanf("%d", &n);
	int res = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			if(arr[i] > arr[j])
				dp[0][i] = max(dp[0][i], dp[0][j]);
			else if(arr[i] < arr[j])
				dp[1][i] = max(dp[1][i], max(dp[0][j], dp[1][j]));
		}
		dp[0][i]++;
		dp[1][i]++;
		res = max(res, max(dp[0][i], dp[1][i]));
	}
	printf("%d\n", res);
	return 0;
}
