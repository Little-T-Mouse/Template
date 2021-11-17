int combination_with_modulor(int n, int r, int m) {
    if (r > n - r) r = n - r;
    int C[r + 1];
    memset(C, 0, sizeof(C));
    C[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = min(i, r); j > 0; j--)
            C[j] = (C[j] + C[j - 1]) % m;
    }
    return C[r];
}
