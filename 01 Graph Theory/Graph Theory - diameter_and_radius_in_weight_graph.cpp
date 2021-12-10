#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 0x3f3f3f3f;

class edge{
public:
    int to, w;
};
int far, len = 0; vector<vector<edge>> graph;
void dfs(int cur, int pre, int dis, int *level) {
    level[cur] = dis;
    if(dis > len) {far=cur; len = dis;}
    for(edge nxt: graph[cur]) {
        if(nxt.to != pre) dfs(nxt.to, cur, dis+nxt.w, level);
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, u, v, w;
    cin >> n;
    graph.resize(n);
    for(int i=0; i<n-1; i++){
        cin >> u >> v >> w;
        u--; v--;
        graph[u].pb(edge{v, w});
        graph[v].pb(edge{u, w});
    }
    int d1[n];
    dfs(0,0,0,d1);
    len = 0;
    dfs(far,0,0,d1);
    int d2[n], d = len; len=0;
    dfs(far,0,0,d2);
    int r = INF;
    for(int i=0; i<n; i++){
        r = min(r, max(d1[i], d2[i]));
    }
    printf("%d\n%d\n", d, r);
    return 0;
}
