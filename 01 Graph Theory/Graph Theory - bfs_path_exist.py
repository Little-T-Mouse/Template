# Python template by Anthony Sheu #
import sys
import collections
import bisect
# sys.setrecursionlimit(1000000)  # comment this out if you are getting memory error on pypy3
readline = lambda: sys.stdin.readline().strip()
readint = lambda: int(sys.stdin.readline())
printf = lambda x: sys.stdout.write("%d\n" % x)  # comment out when using py2
prints = lambda x: sys.stdout.write(x)
printline = lambda x: list(map(print, x))
# printeach = lambda x, y="": print(*x, sep=y)  # x is iterable and y is separator, also comment out when using py2
gi = lambda: list(map(int, readline().split()))
gs = lambda: readline().strip().split()
emp = lambda x, y: [x] * y  # only use for 1d arrays
fill = lambda x: list(range(0, x + 1))
flat = lambda x, l: x.join(map(str, l))  # " \n"[i == n] also works
mat, mit, MOD = sys.maxsize, -sys.maxsize, int(1e9 + 7)
######################## End of Template #######################

def bfs():
    dx, dy = [1, 0, -1, 0], [0, 1, 0, -1]
    q = collections.deque([[1, 1]])
    dist[1][1] = 1
    while q:
        x, y = q.popleft()
        for i in range(4):
            rx, ry = x+dx[i], y+dy[i]
            if rx < 0 or rx == n or ry < 0 or ry == m: continue
            if dist[rx][ry]: continue
            dist[rx][ry] = dist[x][y] + 1
            q.append([rx, ry])

n, m, k = gi()
g = [emp(0, m) for i in range(n)]
dist = [emp(0, m) for i in range(n)]
for i in range(k):
    a, b = gi()
    a -= 1
    b -= 1
    g[a][b] = 1
bfs()
prints("YES\n" if dist[n-1][m-1] else "NO\n")
printline(dist)
