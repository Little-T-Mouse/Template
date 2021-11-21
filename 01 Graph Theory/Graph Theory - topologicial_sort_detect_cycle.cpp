#include <bits/stdc++.h>
using namespace std;
// Author: Little_Mouse
// Direct Graph
vector<vector<int>> graph;
int* indegree; int N;
void topologicial_sort(){
    queue<int> que;
    int cnt = 0;
    for(int i=0; i<N; i++){
        if(indegree[i]==0) que.push(i);
    }
    while(!que.empty()){
        int cur = que.front(); que.pop(); cnt++;
        for(int nxt: graph[cur]) {
            indegree[nxt]--;
            if(indegree[nxt]==0) que.push(nxt);
        }
    }
    if(cnt != N) cout << "Graph has a cycle!" << endl;
    else cout << "No cycle found!" << endl;
}
int main() {
    //cin >> N; <-- input
    N = 6;
    graph.resize(N);
    // Node 0
    // N/A
    // Node 1
    graph[1].push_back(0);
    graph[1].push_back(3);
    // Node 2
    graph[2].push_back(0);
    graph[2].push_back(3);
    // Node 3
    graph[3].push_back(0);
    graph[3].push_back(5);
    // Node 4
    graph[4].push_back(2);
    graph[4].push_back(3);
    graph[4].push_back(5);
    // Node 5
    // N/A
    indegree = new int[N];
    for(int i=0; i<N; i++) indegree[i]=0;
    for(int i=0; i<N; i++){
        for(int to: graph[i]){
            indegree[to]++;
        }
    }
    for(int i=0; i<N; i++){
        cout << "Node " << i << " can be access from " << indegree[i] << " node(s)" << endl;
    }
    topologicial_sort();
    return 0;
}
