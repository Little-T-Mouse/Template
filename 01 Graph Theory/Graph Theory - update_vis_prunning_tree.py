'''
vis[i] = True: but visit
vis[i] = False: can ignore
This program can make all path must visit be true in vis, other be false.
'''
def dfs(v, par):
    for e in g[v]:
        if e == par: continue
        dfs(e, v)
        vis[v] |= vis[e]
 # By Antt (Anthony Sheu)
