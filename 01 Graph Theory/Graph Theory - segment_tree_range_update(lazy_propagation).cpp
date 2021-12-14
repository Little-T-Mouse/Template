#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+2;
struct node { int l, r, v; } seg[4*MM];
int N, Q, ans;
void up(int idx){
    seg[idx].v = min(seg[2*idx].v, seg[2*idx+1].v);
}
void build(int l, int r, int idx){
    seg[idx].l = l; seg[idx].r = r;
    if(l == r) { cin >> seg[idx].v; return; }
    int m = (l + r)/2;
    build(l, m, 2*idx); build(m+1, r, 2*idx+1); up(idx);
}
void update(int pos, int val, int idx){
    if(seg[idx].l == seg[idx].r) { seg[idx].v = val; return; }
    int m = (seg[idx].l + seg[idx].r)/2;
    pos <= m? update(pos, val, 2*idx) : update(pos, val, 2*idx+1);
    up(idx);
}
int query(int l, int r, int k, int idx){
    if(seg[idx].l == seg[idx].r) return seg[idx].v < k? seg[idx].l : -1;
    if(seg[idx].v >= k) return -1;
    int m = (seg[idx].l + seg[idx].r)/2;
    if(r <= m) return query(l, r, k, 2*idx);
    if(l > m) return query(l, r, k, 2*idx+1);
    int tmp = query(l, m, k, 2*idx);
    return tmp != -1? tmp : query(m+1, r, k, 2*idx+1);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q; build(1, N, 1);
    for(int i=1, op, x, y, k; i<=Q; i++) {
        cin >> op >> x >> y;  x ^= ans; y ^= ans;
        if(op == 1) update(x, y, 1);
        else {
            cin >> k;  k^=ans;
            cout << (ans=query(x, y, k, 1)) << "\n";
        }
    }
}
