import math
def isprime(a):
    if a < 2: return False
    elif a == 2: return True
    for i in range(2, math.sqrt(a)):
        if a%i==0: return False
    return True
