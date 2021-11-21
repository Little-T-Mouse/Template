static int n, len=0; static List<edge> adj[];
	public static void main(String[] args) throws IOException{	
		n = readInt(); adj = new ArrayList[n+1];
		for(int i=0; i<=n; i++) adj[i] = new ArrayList<>();
		int sum  = 0;
		for(int i=1; i<=n; i++) {
			int u = readInt(), v = readInt(), w = readInt();  sum+=w;
			adj[u].add(new edge(v, w)); adj[v].add(new edge(u, w));
		}
		dfs(0, -1, 0);
		System.out.println(2*sum - len);
	}
	static void dfs(int u, int p, int d) {
		if(d > len) len = d;
		for(edge e : adj[u]) {
			int v = e.v, w = e.w;
			if(v != p) dfs(v, u, d + w);
		}
	}
	static class edge {
		int v, w;
		edge(int v0, int w0) { v = v0; w = w0; }
	}
