import sys
import math
def mp(n):
        if n==1: return 1,1,0
        else:
            a,b,c = mp(n//2)
            a,b,c = ((a**2+b**2)%MOD,(a*b+b*c)%MOD,(b**2+c**2)%MOD)
        if n%2==1: a,b,c = ((a+b)%MOD,a,b)
        return a,b,c

MOD = int(1e9)+7
N = int(input())
if N == 0:
    print(0)
elif N == 1:
    print(1)
else:
    a,b,c = mp(N-1)
print(a) # mod 1000000007
