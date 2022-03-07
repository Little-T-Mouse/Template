#include <bits/stdc++.h>
using namespace std;

const int ML = 1001;
int dp[ML][ML];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int D, I, R; cin >> D >> I >> R;
    string s, t; cin >> s >> t;
    s = " " + s; t = " " + t;
    for(int i=1; i<=s.size(); i++) dp[i][0] = i*D;
    for(int i=1; i<=t.size(); i++) dp[0][i] = i*I;
    for(int i=1; i<=s.size(); i++){
        for(int j=1; j<=t.size(); j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = min(min(dp[i-1][j]+D, dp[i][j-1]+I), dp[i-1][j-1]+R);
            }
        }
    }
    cout << dp[s.size()][t.size()] << endl;
    return 0;
}
