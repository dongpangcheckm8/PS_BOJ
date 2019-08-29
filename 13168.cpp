// #13168 내일로 여행
https://www.acmicpc.net/problem/13168

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#define INF 987654321
using namespace std;
int n, r, x, y;
string a, b, c;
map<string, int> mp;
vector<int> trip;
int arr[110][110];
int brr[110][110];
void init() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)arr[i][j] = brr[i][j] = 0;
            else arr[i][j] = brr[i][j] = INF;
        }
    }
}
void fw() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][k] + arr[k][j] < arr[i][j])
                    arr[i][j] = arr[i][k] + arr[k][j];
                if (brr[i][k] + brr[k][j] < brr[i][j])
                    brr[i][j] = brr[i][k] + brr[k][j];
            }
        }
    }
}
bool sol() {
    int ac = 0, bc = 0;
    for (int i = 0; i < trip.size() - 1; i++) {
        ac += arr[trip[i]][trip[i + 1]];
        bc += brr[trip[i]][trip[i + 1]];
    }
    return bc + r < ac;
}
int main()
{
    scanf("%d%d", &n, &r);
    init();
    for (int i = 1; i <= n; i++) {
        cin >> a;
        mp[a] = i;
    }
    scanf("%d", &x);
    for (int i = 0; i < x; i++) {
        cin >> a;
        trip.push_back(mp[a]);
    }
    scanf("%d", &x);
    for (int i = 0; i < x; i++) {
        cin >> a >> b >> c;
        scanf("%d", &y);
        arr[mp[b]][mp[c]] = min(y, arr[mp[b]][mp[c]]);
        arr[mp[c]][mp[b]] = min(y, arr[mp[b]][mp[c]]);
        if (a == "S-Train" || a == "V-Train") {
            brr[mp[b]][mp[c]] = min(y / 2, brr[mp[b]][mp[c]]);
            brr[mp[c]][mp[b]] = min(y / 2, brr[mp[b]][mp[c]]);
        }
        else if(a=="Mugunghwa"||a=="ITX-Saemaeul"||a=="ITX-Cheongchun") {
            brr[mp[b]][mp[c]] = 0;
            brr[mp[c]][mp[b]] = 0;
        }
        else {
            brr[mp[b]][mp[c]] = min(y, brr[mp[b]][mp[c]]);
            brr[mp[c]][mp[b]] = min(y, brr[mp[b]][mp[c]]);
        }
    }
    fw();
    printf("%s\n", sol() ? "Yes" : "No");
    return 0;
}
