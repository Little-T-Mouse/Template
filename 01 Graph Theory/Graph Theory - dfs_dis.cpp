#include <bits/stdc++.h>
using namespace std;
queue<int> que;
vector<vector<int>> graph;
int vis;
int level;
int dfs_dis(int cur, int des, int dis){
    if(cur == des) return level = dis;
    vis[cur] = true; que.push(cur);
    for(int next: graph[cur]){
        if(!vis[next]) dfs_dis(next, des, dis+1);
    }
    return level;
}
int main(){
    memset(vis, false, sizeof(vis));
    graph[1].push_back(2);
    graph[4].push_back(5);
    graph[2].push_back(3);
    cout << dfs_dis(1,3,0) << endl;
    return 0;
}
