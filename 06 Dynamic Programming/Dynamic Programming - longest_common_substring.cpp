// Educational DP Contest AtCoder F - LCS
#include <bits/stdc++.h>
using namespace std;

const int ML = 3003;
int dp[ML][ML];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    string s, t, ans = ""; cin >> s >> t;
    for(int i=1; i<=s.size(); i++){
        for(int j=1; j<=t.size(); j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int x = s.size(), y = t.size();
    while(x && y){
        if(dp[x][y] == dp[x-1][y]) x--;
        else if(dp[x][y] == dp[x][y-1]) y--;
        else{ans.push_back(s[x-1]); x--; y--;}
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}
