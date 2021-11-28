#include <bits/stdc++.h>
using namespace std;
/*
    Minimum Spanning Tree Prim Algorithm
    Time Complexity: O(ElogV)
    Author: Little_Mouse
*/
class edge{
public:
    int to;
    int weight;

    //edge(int weight, int to): weight(weight), to(to){}
    edge(int to, int weight){
        this->to = to;
        this->weight = weight;
    };
};
bool operator<(const edge& e1, const edge& e2){
    return e1.weight < e2.weight;
}
bool operator>(const edge& e1, const edge& e2){
    return e1.weight > e2.weight;
}
int N; int* dis; vector<vector<edge>> graph;
int* pre; // Optional
void prim(){
    priority_queue<edge, vector<edge>, greater<edge>> que;
    que.push(edge{1,0});
    bool vis[N+1]; memset(vis, false, sizeof(vis));
    while(!que.empty()){
        edge node = que.top(); que.pop();
        vis[node.to]=true;
        for(edge adj: graph[node.to]){
            //cout << node.to << " " << adj.to << " " << adj.weight << " " << dis[adj.to] << " "<< adj.weight << endl;
            if(vis[adj.to]) continue;
            que.push(adj);
            if(dis[adj.to]>adj.weight){
                dis[adj.to] = adj.weight;
                pre[adj.to] = node.to;
            }
        }
    }
}

int main() {
    // cin >> N; <-- Input
    N = 6;
    dis = new int[N+1]; pre = new int[N+1];
    for(int i=0; i<=N; i++) dis[i] = 0x3f3f3f3f;
    dis[1] = 0; graph.resize(N+1); // Start from point A (1)
    // Node A (1):
    graph[1].push_back(edge{2,34});
    graph[1].push_back(edge{3,46});
    graph[1].push_back(edge{6,19});
    // Node B (2):
    graph[2].push_back(edge{1,34});
    graph[2].push_back(edge{5,12});
    // Node C (3):
    graph[3].push_back(edge{1,46});
    graph[3].push_back(edge{4,17});
    graph[3].push_back(edge{6,25});
    // Node D (4):
    graph[4].push_back(edge{3,17});
    graph[4].push_back(edge{5,38});
    graph[4].push_back(edge{6,25});
    // Node E (5):
    graph[5].push_back(edge{2,12});
    graph[5].push_back(edge{4,38});
    graph[5].push_back(edge{6,26});
    // Node F (6):
    graph[6].push_back(edge{1,19});
    graph[6].push_back(edge{3,25});
    graph[6].push_back(edge{4,25});
    graph[6].push_back(edge{5,26});
    prim();
    cout << "The Minimum Spanning Tree is: " << endl;
    cout << "Start Point 1, distance: 0"<<endl;
    for(int i=2; i<=N; i++){
        cout << pre[i] << " -> " << i << ", distance: " << dis[i] << endl;
    }
    return 0;
}
