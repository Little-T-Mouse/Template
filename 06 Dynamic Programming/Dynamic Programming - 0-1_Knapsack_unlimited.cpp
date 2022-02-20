#include<bits/stdc++.h>
using namespace std;

struct item{ int v, w; };
vector<item> items = {{1, 2}, {3, 3}, {5, 1}, {2, 5}, {6, 3}, {10, 5}};

int Knapsack(int W) {
    int dp[W+1]; memset(dp, 0, sizeof(dp));
    for(int i=0; i < items.size(); i++){
        for(int j=items[i].w; j<=W; j--){
            dp[j] = max(dp[j], items[i].v + dp[j-items[i].w]);
        }
    }
    return dp[W];
}

int main() {
    int W; cin >> W;
    cout << Knapsack(W) << endl;
    return 0;
}
