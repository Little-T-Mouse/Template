int bfs_dis(int from, int to){ // Find distance between two point
    // Array level need init and declear out of the function "bfs_dis".
    queue<int> que; bool vis[N];
    memset(vis, false, sizeof(vis)); que.push(start);
    while(!que.empty()){
        int node = que.front(); que.pop();
        if(node == to) return level[node];
        for(int next: graph[node]){
            if(!vis[next]){
                vis[next] = true;
                level[next] = level[node]+1;
                que.push(next);
            }
        }
    }
    return -1;
}
