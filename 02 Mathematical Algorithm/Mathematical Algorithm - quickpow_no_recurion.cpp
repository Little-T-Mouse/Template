int power(int base, int exponent) {
    int res = 1;
    while (exponent > 0) {
        if (exponent & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exponent >>= 1;
    }
    return res;
}
