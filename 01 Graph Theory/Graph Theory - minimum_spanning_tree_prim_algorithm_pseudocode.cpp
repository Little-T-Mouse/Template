Arrays.fill(dis, inf ) ;
dis[start] = 0
for(int k=1; k<=n; k++ ) {
	int min = inf, u = -1;
	for(int i=1; i<=n; i++) {
		if( !vis[i] && dis[i] < min) { min = dis[i] ;  u = i; }
	}
	if( u == -1) break;
	vis[u] = true;
	for(edge e : adj[u] ) {
		v = e.v   w = e.w
		if(!vis[v] && dis[v] > w ) dis[v] = w;
	}
}
