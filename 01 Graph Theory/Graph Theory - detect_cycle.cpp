#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;

void add_edge(int u, int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}
bool iscycle(int sta, int v, bool vis[]){
    int parent[v]; memset(parent, -1, sizeof(parent));
    queue<int> que;
    vis[sta]=true; que.push(sta);
    while(!que.empty()){
        int node = que.front(); que.pop();
        for(int next: graph[node]){
            if(!vis[next]){
                vis[next]=true;
                que.push(next);
                parent[next]=node;
            }
            else if(parent[node] != next) return true;
        }
    }
    return false;
}
bool iscyclediscon(int v){
    bool vis[v]; memset(vis, false, sizeof(vis));
    for(int i=0; i<v; i++){
        if(!vis[i]&&iscycle(i,v,vis)) return true;
    }
    return false;
}
int main(){
    int N, M, a, b;
    cin >> N >> M;
    graph.resize(N);
    for(int i=0; i<M; i++){
        cin >> a >> b;
        add_edge(a,b);
    }
    if(iscyclediscon(N)) cout << "Yes" << endl;
    else cout << "No" << endl;
}
