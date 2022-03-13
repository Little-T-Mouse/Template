// Longest Increasing Subsequence
#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6+6, INF = 0x3f3f3f3f;
int N, LIS; vector<int> val(MAX, INF);
int main() {
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N; val[0] = 0;
    for(int i=1, a, idx; i<=N; i++){
        cin >> a;
        idx = lower_bound(val.begin(), val.end(), a) - val.begin();
        val[idx] = a;
    }
    for(int i=1; i<=N; i++){
        if(val[i] >= INF) break;
        LIS++;
    }
    cout << LIS << endl;
    return 0;
}
