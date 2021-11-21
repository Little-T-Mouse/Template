#include <bits/stdc++.h>
using namespace std;
/*
This program contain:
  - A class edge which is use in weight graph
    - Which node this node connect
    - How far between these two node
  - A BFS function find the distance to each nodes
  - A farest function to find the farest node from one end point
  - 2*E-max(level2[i],level3[i])-1 for output the shortest distance need to go
*/


class edge{
public:
    int to;
    int dis;
};
vector<vector<edge>> graph;
int N, T, E = 0;
void bfs(int sta, int level[]){
	fill(level, level+N, -1);
	queue<edge> que;
	que.push(edge{sta, 0});
	while(!que.empty()){
		edge cur = que.front(); que.pop();
		for(edge adj: graph[cur.to]){
			if(level[adj.to] != -1) continue;
			level[adj.to] = level[cur.to] + adj.dis;
			que.push(adj);
		}
	}
}
int farest(int level[]){
	int far = -1, len = -1;
	for(int i=0; i<N; i++){
		if(level[i] > len){
			len = level[i];
			far = i;
		}
	}
	return far;
}
int main() {
    int a, b, c;
    cin >> N >> T;
    graph.resize(N);
    int connect[N];
    memset(connect, 0, sizeof(connect));
    for(int i=0; i<N-1; i++){
        cin >> a >> b >> c;
        a--; b--; connect[a]++; connect[b]++; E += c;
        graph[a].push_back(edge{b,c});
        graph[b].push_back(edge{a,c});
    }
    int level1[N],level2[N],level3[N];
    bfs(0, level1);
    int far1 = farest(level1);
    bfs(far1, level2);
    int far2 = farest(level2);
    bfs(far2, level3);
    for(int i=0; i < N; i++){
		   cout << i+1 << " " << 2*E-max(level2[i],level3[i])-1 << endl;
	  }
    return 0;
}
