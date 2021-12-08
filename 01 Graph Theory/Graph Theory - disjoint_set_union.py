# DSU #
def findset(d):
    if d != p[d]: p[d] = findset(p[d])
    return p[d]

def union(a, b):
    a, b = findset(a), findset(b)
    if a != b:
        if s[a] < s[b]: a, b = b, a
        p[b] = a
        if s[a] == s[b]: s[a] += 1
            
def union(a, b):
    a, b = findset(a), findset(b)
    if a == b: return
    if s[a] >= s[b]:
        s[a] += s[b]
        p[b] = a
    else:
        s[b] += s[a]
        p[a] = b
