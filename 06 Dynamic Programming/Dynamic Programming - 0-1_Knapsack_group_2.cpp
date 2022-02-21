#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
const int MM = 105;
int N, T, dp[MM]; vector<pi> skill[MM];
int main(){
    scanf("%d %d", &N, &T);
    for(int i=1, M; i<=N; i++){
        scanf("%d", &M); int w = 0, v = 0;
        for(int j=1, t, x; j<=M; j++){
            scanf("%d %d", &t, &x);  w+=t; v+=x;
            skill[i].push_back({w, v});
        }
    }
    for(int i=1; i<=N; i++){
        for(int j=T; j>=0; j--){
            for(auto &e: skill[i]){
                int w = e.first, v = e.second;
                if(j>=w) dp[j] = max(dp[j], dp[j-w]+v);
            }
        }
    }
    printf("%d\n", dp[T]);
}
