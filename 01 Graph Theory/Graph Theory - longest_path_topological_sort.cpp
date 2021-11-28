#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define endl "\n"
#define pb push_back

using namespace std;
int ind[100001]; int dp[100001];
vector<list<int>> adj(100001);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        ind[b]++;
    }
    //Topological Sort
    queue<int> queue;
    for(int i = 1; i <= n; i++){
        if(ind[i] == 0){
            queue.push(i);
        }
    }
    while(!queue.empty()){
        int cur = queue.front(); queue.pop();
        for(auto i:adj[cur]){
            ind[i]--;
            if(ind[i] == 0){
                queue.push(i);
                dp[i] = max(dp[i], dp[cur]+1);
            }
        }
    }
    int maxv = 0;
    for(int i = 1; i <= n; i++){
        maxv = max(maxv, dp[i]);
    }
    cout << maxv << endl;
    return 0;
}
