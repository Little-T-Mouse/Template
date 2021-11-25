#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

mt19937_64 mt(time(NULL));
ll quickMul(ll x, ll y, ll mod) {
    if (y==0) return 0;
    return (x*(y&1)+quickMul((x+x)%mod,y>>1,mod))%mod;
}
ll quickPow(ll x, ll y, ll mod) {
    if (y==0) return 1;
    return quickMul((y&1?x:1),quickPow(quickMul(x,x,mod),y>>1,mod),mod);
}
bool isprime(ll n){
    if(n<=1) return false;
    if(n<=3) return true;
    uniform_int_distribution<ll> dis(2,n);
    for(int i=0; i<50; i++){
        ll rand = dis(mt);
        if(rand == n){i--; continue;}
        if(quickPow(rand,n-1,n)!=1) return false;
    }
    return true;
}
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    ll n; cin >> n; if(n<2)n=2; while(true){if(isprime(n)){cout<<n<<endl;break;}n++;}
    return 0;
}
