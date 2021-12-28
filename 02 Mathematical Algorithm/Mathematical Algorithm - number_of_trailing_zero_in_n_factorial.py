def cntTrailingZeros(n):
    cnt = 0
    while(n >= 5):
        n //= 5
        cnt += n
    return cnt

n = int(input())
print("Count of trailing 0(s) in"+str(n)+"! is", cntTrailingZeros(n))
