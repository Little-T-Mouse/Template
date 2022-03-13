#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 4e5+5;
int N, M, D, dis[MAX], cnt[MAX]; vector<int> graph[MAX]; ll num;
void dfs(int cur, int pre){
    dis[cur] = 0; cnt[cur] = 1;
    for(int nxt: graph[cur]){
        if(nxt == pre) continue;
        dfs(nxt, cur);
        if(dis[cur]+1+dis[nxt]>D){
            D = dis[cur]+1+dis[nxt];
            num = 1LL*cnt[cur]*cnt[nxt];
        }
        else if(dis[cur]+1+dis[nxt]==D){
            num += 1LL*cnt[cur]*cnt[nxt];
        }
        if(dis[nxt]+1>dis[cur]){
            dis[cur] = dis[nxt]+1;
            cnt[cur] = cnt[nxt];
        }
        else if(dis[nxt]+1==dis[cur]){
            cnt[cur] += cnt[nxt];
        }
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=1, u, v; i<N; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, 0);
    cout << D+1 << " " << num << endl;
    return 0;
}
