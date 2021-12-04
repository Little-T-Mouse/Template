def mst():  # 0 indexed, using adj-matrix
    vis = emp(0, n)
    dist = emp(mat, n)
    dist[r] = 0  # replace r with starting node
    for _ in range(n):
        m, v = mat, -1
        for i in range(n):
            if not vis[i] and dist[i] < m: m = dist[i]; v = i
        if v == -1: break
        vis[v] = 1
        for i in range(n):
            if not vis[i] and dist[i] > g[v][i]: dist[v] = g[v][i]
    return sum(d)
  # By Anthony-Sheu
