class point{
public:
    int x;
    int y;
};
int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

int bfs_dis_2(point from, point des){ // Find the distance between two node
    int level[R][C]; queue<point> que; bool vis[R][C]; point tmp;
    memset(vis, false, sizeof(vis)); que.push(start); memset(level, 0, sizeof(level));
    while(!que.empty()){
        point node = que.front(); que.pop();
        if(node.x == des.x && node.y == des.y) return level[node.x][node.y];
        for(int i=0; i<4; i++){
            int nx = node.x+dx[i]; int ny = node.y+dy[i];
            if(nx>=0&&nx<R&&ny>=0&&ny<C&&!vis[nx][ny]){ // Can add more(e.g. grid[nx][ny] != 'X')
                vis[nx][ny] = true;
                tmp.x = nx; tmp.y = ny;
                que.push(tmp);
                level[nx][ny] = level[node.x][node.y]+1;
            }
        }
    }
    return -1;
}
