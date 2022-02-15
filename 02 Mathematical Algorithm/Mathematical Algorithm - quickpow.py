def quickpow(x, n, mod):
    if n == 0:
        return 1
    t = quickpow(x, n/2, mod)
    t = t*t % mod
    if n % 2 == 0:
        return t
    return t*x % mod
