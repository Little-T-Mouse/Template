int bfs_furthest_node(int from){ // Find the farest node from a node
    int level[N]; queue<int> que; bool vis[N];
    memset(vis, false, sizeof(vis)); que.push(start); memset(level, 0, sizeof(level)); int farest=-1;
    while(!que.empty()){
        int node = que.front(); que.pop();
        for(int next: graph[node]){
            if(!vis[next]){
                vis[next] = true;
                que.push(next);
                level[next] = level[node]+1;
                if(level[next]>farest) farest = level[next];
            }
        }
    }
    return farest;
}
