#include <bits/stdc++.h>
using namespace std;

class path{
public:
    int to;
    int len;
};
void dijkstra_min_distance(int dis[], int sta, vector<vector<path>> graph){
    queue<path> que;
    que.push(path{sta,0});
    dis[sta] = 0;
    while(!que.empty()){
        path cur = que.front(); que.pop();
        if(cur.len > dis[cur.to]) continue;
        for(path next: graph[cur.to]){
            if(dis[next.to]>dis[cur.to]+next.len){
                dis[next.to] = dis[cur.to]+next.len;
                que.push(path{next.to, dis[next.to]});
            }
        }
    }
}
// Example:
/*
  from  to  length
  1     2   5
  1     3   5
  3     5   10
  2     5   6
*/
int main() {
    int N = 5;
    vector<vector<path>> graph(N+1);
    graph[1].push_back(path{2,5});
    graph[1].push_back(path{3,5});
    graph[3].push_back(path{5,10});
    graph[2].push_back(path{5,6});
    int dis[N+1]; memset(dis, 0x3f3f3f3f, sizeof(dis));
    dijkstra_min_distance(dis, 1, graph); // From node 1
    for(int i=0; i<=N; i++){
        cout << "The min distance to node " << i << " is: " << ((dis[i] == 0x3f3f3f3f) ? -1 : dis[i]) << endl;
    }
    return 0;
}
