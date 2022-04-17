void dfs1(int cur, int pre){
    sz[cur] = zone[cur];
    for(pair<int, int> pi: graph[cur]){
        if(pi.first == pre) continue;
        dfs1(pi.first, cur); sz[cur] += sz[pi.first];
    }
}

int centroid(int cur, int pre){
    for(pair<int, int> pi: graph[cur]){
        if(pi.first == pre) continue;
        if(2*sz[pi.first] > K) return centroid(pi.first, cur);
    }
    return cur;
}
