ll quickMul(ll x, ll y, ll mod) {
    if (y==0) return 0;
    return (x*(y&1)+quickMul((x+x)%mod,y>>1,mod))%mod;
}
ll quickPow(ll x, ll y, ll mod) {
    if (y==0) return 1;
    return quickMul((y&1?x:1),quickPow(quickMul(x,x,mod),y>>1,mod),mod);
}
