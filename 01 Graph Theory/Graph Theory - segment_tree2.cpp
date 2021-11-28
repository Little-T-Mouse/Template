#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
struct node { int l, r, mi, g, f;} tree[3*MM];
int n, m; char op;
void pushup(int idx){
    tree[idx].mi = min(tree[2*idx].mi, tree[2*idx+1].mi);
    tree[idx].g = __gcd(tree[2*idx].g, tree[2*idx+1].g);
    tree[idx].f = 0;
    if(tree[idx].g == tree[2*idx].g) tree[idx].f += tree[2*idx].f;
    if(tree[idx].g == tree[2*idx+1].g) tree[idx].f += tree[2*idx+1].f;
}
void build(int l, int r, int idx){
    tree[idx].l = l; tree[idx].r = r;
    if(l == r) { cin >> tree[idx].mi;  tree[idx].g=tree[idx].mi; tree[idx].f=1; return; }
    int mid = (l + r)/2;
    build(l, mid, 2*idx); build(mid+1, r, 2*idx+1);
    pushup(idx);
}
void update(int pos, int val, int idx){
    if(tree[idx].l == tree[idx].r) { tree[idx].g=tree[idx].mi = val; return;}
    int mid = (tree[idx].l + tree[idx].r)/2;
    pos <= mid? update(pos, val, 2*idx) : update(pos, val, 2*idx+1);
    pushup(idx);
}
int queryMin(int l, int r, int idx){
    if(tree[idx].l == l && tree[idx].r==r) return tree[idx].mi;
    int mid = (tree[idx].l + tree[idx].r)/2;
    if(r <= mid) return queryMin(l, r, 2*idx);
    if(l > mid) return queryMin(l, r, 2*idx+1);
    return min(queryMin(l, mid, 2*idx), queryMin(mid+1, r, 2*idx+1));
}
int queryGcd(int l, int r, int idx){
    if(tree[idx].l == l && tree[idx].r==r) return tree[idx].g;
    int mid = (tree[idx].l + tree[idx].r)/2;
    if(r <= mid) return queryGcd(l, r, 2*idx);
    if(l > mid) return queryGcd(l, r, 2*idx+1);
    return __gcd(queryGcd(l, mid, 2*idx), queryGcd(mid+1, r, 2*idx+1));
}
int queryFreq(int l, int r, int g, int idx){
    if(tree[idx].l == l && tree[idx].r==r) return tree[idx].g == g? tree[idx].f : 0;
    int mid = (tree[idx].l + tree[idx].r)/2;
    if(r <= mid) return queryFreq(l, r, g, 2*idx);
    if(l > mid) return queryFreq(l, r, g, 2*idx+1);
    return queryFreq(l, mid, g, 2*idx) + queryFreq(mid+1, r, g, 2*idx+1);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m; build(1, n, 1);
    for(int i=1, x, y; i<=m; i++) {
        cin >> op >> x >> y;
        if(op == 'C') update(x, y, 1);
        if(op == 'M') cout << queryMin(x, y, 1) << "\n";
        if(op == 'G') cout << queryGcd(x, y, 1) << "\n";
        if(op == 'Q') cout << queryFreq(x, y, queryGcd(x, y, 1), 1) << "\n";
    }
}
