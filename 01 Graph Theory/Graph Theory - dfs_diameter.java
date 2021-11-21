	public static void main(String[] args) throws IOException{
		dfs(1, -1, 0); len = 0; dfs(far, -1, 0);
		System.out.println(far);
	}
	static void dfs(int cur, int pre, int dis) {
		if(dis > len) {far=cur; len = dis;}
		for(int nxt: adj[cur]) {
			if(nxt != pre) dfs(nxt, cur, dis+1);
		}
	}
