def dijkstra_weighted():  # import heapq as hp
    dist = emp(mat, n+1)
    vis = emp(0, n+1)
    dist[1] = 0  # set 1 as your starting node
    q = [1]
    hp.heapify(q)
    while q:
        pos = hp.heappop(q)
        vis[pos] = 1
        for e, w in g[pos]:
            if not vis[e]:
                if dist[pos]+w < dist[e]:
                    hp.heappush(q, e)
                    dist[e] = dist[pos]+w
    return dist
# Author: Anthoy Sheu
