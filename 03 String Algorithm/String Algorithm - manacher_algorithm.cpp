// CCO '97 P1 - Palindromes
#include <bits/stdc++.h>
using namespace std;
const int MN = 25005;
int n, sz, r[MN*2], cen, cnt, ans, st; char t[MN*2]; string s;

void manacher(){
    int p = 0, mx = 0, len = 2*sz+1;
    for(int i=0; i<len; i++){
        if(i > mx) r[i] = 1;
        else r[i] = min(r[2*p - i], mx - i);
        while(i >= r[i] && t[i+r[i]] == t[i-r[i]]) r[i]++;
        if(i + r[i] > mx) mx = i + r[i], p = i;
        if(r[i] > ans) ans = r[i], cen = i;
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int T=0; T<n; T++){
        cin >> s; sz = s.size();
        cen = 0, cnt = 0, ans = 0; memset(r, 0, sizeof r);
        for(int i=0; i<sz; i++) t[2*i] = '#', t[2*i+1] = s[i]; t[2*sz] = '#'; t[2*sz+1] = '.';
        manacher();
        for(int i=cen-ans+1; i<cen+ans; i++){
            if(t[i] != '#') { cout << t[i]; cnt++; }
        }
        cout << "\n" << cnt << "\n";
    }
    return 0;
}
