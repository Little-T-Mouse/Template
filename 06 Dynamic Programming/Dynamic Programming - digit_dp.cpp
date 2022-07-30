#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
int D; ll dp[10004][1001][2]; string K;

ll solve(int pos, int tot, int hi) {
    if(dp[pos][tot][hi] != -1) return dp[pos][tot][hi];
    if(pos == K.size()) return (tot % D == 0);
    int up = hi ? K[pos] - '0' : 9; ll ret = 0;
    for(int i=0; i<=up; i++)
        ret = (ret + solve(pos + 1, (tot + i) % D, hi && i == (K[pos] - '0'))) % mod;
    return dp[pos][tot][hi] = ret;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> K >> D; memset(dp, -1, sizeof dp);
    cout << (solve(0, 0, 1) - 1 + mod) % mod << endl;
    return 0;
}
