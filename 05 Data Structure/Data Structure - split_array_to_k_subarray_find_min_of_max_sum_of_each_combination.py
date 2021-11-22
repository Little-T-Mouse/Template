# Approch: Binary Search
'''
Split the given array into K sub-arrays such that maximum sum of all sub arrays is minimum.
'''
# Version 1:
def check(mid, array, n, K):
    count = 0
    sum = 0
    for i in range(n):
        if array[i] > mid: return False
        sum += array[i]
        if (sum > mid):
            count += 1
            sum = array[i]
    count += 1
    if count <= K: return True
    return False

def solve(array, n, K):
    start = max(array)
    end = 0
    for i in range(n):
        end += array[i]
    answer = 0
    while start <= end:
        mid = (start + end) // 2
        if (check(mid, array, n, K)):
            answer = mid
            end = mid - 1
        else:
            start = mid + 1
    return answer

N, K = list(map(int, input().split()))
l = list(map(int, input().split()))

print(solve(l, N, K))
#######################################
# Version 2: Antt (Anthoy Sheu)
def solve():
    s, e = max(f), sum(f)
    ans = 0
    while s <= e:
        mid = (s+e)//2
        if check(mid): ans = mid; e = mid-1
        else: s = mid+1
    return ans

def check(mid):
    c, s = 0, 0
    for i in range(n):
        if f[i] > mid: return 0
        s += f[i]
        if s > mid: c += 1; s = f[i]
    c += 1
    return c <= m

n, m = list(map(int, input().split()))
f = list(map(int, input().split()))

print(solve())

# Note: From https://www.geeksforgeeks.org/split-the-given-array-into-k-sub-arrays-such-that-maximum-sum-of-all-sub-arrays-is-minimum/
