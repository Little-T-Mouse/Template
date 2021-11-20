MOD = int(1e9) + 7
def multiply(A, B): return (((A[0][0] * B[0][0] + A[0][1] * B[1][0]) % MOD,(A[0][0] * B[0][1] + A[0][1] * B[1][1]) % MOD),((A[1][0] * B[0][0] + A[1][1] * B[1][0]) % MOD,(A[1][0] * B[0][1] + A[1][1] * B[1][1]) % MOD))
def binary(power):
    global mat
    stable = mat
    while power != 0:
        if power&1 == 1:
            stable = multiply(mat, stable)
        mat = multiply(mat, mat)
        power >>= 1
    return stable
n = int(input())
mat = ((1,1),(1,0))
print(binary(n)[1][1] % MOD) # mod 1000000007
