bool bfs_path_exist(int from, int to){ // Find if there are a path between two point
    queue<int> que; bool vis[N];
    memset(vis, false, sizeof(vis)); que.push(start);
    while(!que.empty()){
        int node = que.front(); que.pop();
        if(node == to) return true;
        for(int next: graph[node]){
            if(!vis[next]){vis[next] = true; que.push(next);}
        }
    }
    return false;
}
