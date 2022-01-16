#include <bits/stdc++.h>
using namespace std;
const int MM = 1002;
typedef pair<int, int> pi;
int N, M, dis[MM]; bool vis[MM]; vector<pi> adj[MM];
int main(){
    cin >> N >> M;
    for(int i=1, u, v, w; i<=M; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); adj[v].push_back({u, w});
    }
    priority_queue<pi, vector<pi>, greater<pi> > q;
    fill(dis, dis+MM, 1e9);
    dis[1] = 0; q.push({dis[1], 1});
    while(!q.empty()) {
        int d = q.top().first, u = q.top().second; q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(pi e : adj[u]){
            int v = e.first, w = e.second;
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w; q.push({dis[v], v});
            }
        }
    }
    for(int i=1; i<=N; i++)
        cout << (vis[i]? dis[i] : -1) << "\n";
}
