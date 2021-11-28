#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph; bool vis[100001]; int dp[100001];
int find_longest_to(int i){
    if(vis[i]) return dp[i];
    vis[i]=true; int longest=0;
    for(int nxt: graph[i]){longest = max(longest, find_longest_to(nxt)+1);}
    return dp[i]=longest;
}
int main(){
    int N, M, x, y, longest = 0; cin >> N >> M;
    graph.resize(N+1); memset(vis, false, sizeof(vis)); memset(dp, 0, sizeof(dp));
    while(M--){cin >> x >> y; graph[x].push_back(y);}
    for(int i=1; i<=N; i++) longest = max(longest, find_longest_to(i));
    cout << longest << endl; return 0;
}
