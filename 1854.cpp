// #1854 K번째 최단경로 찾기
https://www.acmicpc.net/problem/1854

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
#define INF 987654321
using namespace std;

typedef pair<int, int> pii;

vector <pii> vc[1002];
priority_queue<int> dist[1002];
int n, m, k;

int main(void){
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= m; i++){
		int from, to, val;
		scanf("%d %d %d", &from, &to, &val);
		vc[from].push_back({val, to});
	}
	priority_queue<pii, vector<pii>, greater<> > pq;
	pq.push({0, 1});
	dist[1].push(0);
	
	while(!pq.empty()){
		int here = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		
		for(int i = 0; i < vc[here].size(); i++){
			int next = vc[here][i].second;
			int next_cost = vc[here][i].first;
			
			if(dist[next].size() < k){
				dist[next].push(next_cost + cost);
				pq.push({next_cost + cost, vc[here][i].second});
			}
			else if(dist[next].top() > next_cost + cost){
				dist[next].pop();
				dist[next].push(next_cost + cost);
				pq.push({next_cost + cost, vc[here][i].second});
			}
		}
	}
	for(int i = 1; i <= n; i++)
		dist[i].size() == k ? printf("%d\n", dist[i].top()) : printf("-1\n");
	return 0;
}
