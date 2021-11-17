// Modular Inversion Technique
int combination(int n, int r){
    if (r > n) return 0;
    long long int m = 1000000007;
    long long int inv[r + 1] = {0};
    inv[0] = 1;
    if(r+1>=2) inv[1] = 1;

    for (int i = 2; i <= r; i++) {
        inv[i] = m - (m / i) * inv[m % i] % m;
    }
  
    int ans = 1;

    for (int i = 2; i <= r; i++) {
        ans = ((ans % m) * (inv[i] % m)) % m;
    }
  
    for (int i = n; i >= (n - r + 1); i--) {
        ans = ((ans % m) * (i % m)) % m;
    }
    return ans;
}
