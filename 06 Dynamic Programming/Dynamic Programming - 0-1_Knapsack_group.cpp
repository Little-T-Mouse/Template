#include <bits/stdc++.h>
using namespace std;

int w[105][105], v[105][105], dp[105];
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N, T; cin >> N >> T;
    for(int i=0; i<N; i++){
        int L; cin >> L;
        for(int j=0; j<L; j++){
            int t, x; cin >> t >> x;
            w[i][j+1] = w[i][j] + t;
            v[i][j+1] = v[i][j] + x;
        }
    }
    for(int i=0; i<N; i++){
        for(int j=T; j>=0; j--){
            for(int k=0; k<105; k++){
                if(j-w[i][k]>=0){
                    dp[j] = max(dp[j], dp[j-w[i][k]]+v[i][k]);
                }
            }
        }
    }
    cout << dp[T] << endl;
    return 0;
}
