#include <bits/stdc++.h>
using namespace std;
int n; vector<int> lis;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i=1, x; i<=n; i++){
        cin >> x;
        if(lis.empty() || x > lis.back()) lis.push_back(x);
        else *lower_bound(lis.begin(), lis.end(), x) = x;
    }
    cout << lis.size() << endl;
}
