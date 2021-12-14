#include <bits/stdc++.h>
using namespace std;
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
char _inp[4097], *_pinp=_inp;
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;
#define f first
#define s second
#define lc (rt<<1)
#define rc (rt<<1|1)
#define pb push_back
#define cl(a, b) memset(a, b, sizeof(a))
#define mp(a, b) make_pair((a), (b))
#define all(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<pi, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vii;
typedef vector<pl> vll;
typedef vector<pii> viii;
const int inf = 0x3F3F3F3F;
const ll infl = 0x3F3F3F3F3F3F3F3FLL;
const int mod = 1e9 + 7, MM = 1e6+2;
struct node{ int l, r, v; } seg[4*MM];
int n, m, ans;
void build(int l, int r, int rt){
    seg[rt].l = l; seg[rt].r = r;
    if(l == r) { scan(seg[rt].v); return; }
    int mid = (l + r)/2;
    build(l, mid, lc); build(mid+1, r, rc);
    seg[rt].v = min(seg[lc].v, seg[rc].v);
}
void update(int pos, int val, int rt){
    if(seg[rt].l == seg[rt].r) { seg[rt].v = val; return; }
    int mid = (seg[rt].l + seg[rt].r)/2;
    if(pos <= mid) update(pos, val, lc);
    else update(pos, val, rc);
    seg[rt].v = min(seg[lc].v, seg[rc].v);
}
int query(int l, int r, int k, int rt){
    if(seg[rt].l == l && seg[rt].r == r){
        if(seg[rt].v >= k) return inf;
        int lo = l, hi = r, ch = rt;
        while(lo < hi){
            int mid = (lo + hi)/2;
            if(seg[lc].v < k) { hi = mid; rt = lc;}
            else { lo = mid + 1; rt = rc;}
        }
        return lo;
    }
    int mid = (seg[rt].l + seg[rt].r)/2;
    if(r <= mid) return query(l, r, k, lc);
    if(l > mid) return query(l, r, k, rc);
    int p = query(l, mid, k, lc);
    return p != inf? p: query(mid+1, r, k, rc);
}
int main(){
    //freopen("test.txt", "r", stdin);
    scan(n); scan(m); build(1, n, 1);
    for(int i=0, op, a, b, c; i<m; i++){
        scan(op);
        if(op==1){
            scan(a); scan(b); a^=ans; b^=ans;
            update(a, b, 1);
        }else{
            scan(a); scan(b); scan(c); a^=ans; b^=ans; c^=ans;
            ans = query(a, b, c, 1); printf("%d\n", ans);
        }
    }
}
