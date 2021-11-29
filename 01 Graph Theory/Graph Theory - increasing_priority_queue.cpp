#include <bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int, vector<int>, greater<int>> q;
    q.push(5);
    q.push(3);
    q.push(8);
    q.push(1);  //[-1, -3, -5, -8]
    while(!q.empty()){
        int u = q.top(); q.pop();
        cout << u << endl;
    }
}
