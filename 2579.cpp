// #2579. 계단 오르기
https://www.acmicpc.net/problem/2579

#include <stdio.h>

int n;
int arr[301];
int dp[301];

int max(int a, int b){return (a > b) ? a : b;}

int main(void){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	dp[0] = arr[0];
	dp[1] = max(arr[0] + arr[1], arr[1]);
	dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);
	for(int i = 3; i < n; i++){
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
	}
	printf("%d\n", dp[n - 1]);
	return 0;
}
