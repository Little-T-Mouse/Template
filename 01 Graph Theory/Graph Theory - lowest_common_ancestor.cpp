int LCA(int cur, int pre){
    if(depth[cur] < depth[pre]) swap(cur, pre);
    int dif = depth[cur] - depth[pre];
    for(int i=0; i<20; i++){
        if((dif>>i)&1) cur = p[i][cur];
    }
    if(cur == pre) return cur;
    for(int i=19; i>=0; i--){
        if(p[i][cur] != p[i][pre]){
            cur = p[i][cur];
            pre = p[i][pre];
        }
    }
    return p[0][cur];
}
