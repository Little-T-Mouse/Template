static long memo[];
	public static void main(String[] args) throws IOException{	
		int n = readInt(); memo = new long[n+1];
		System.out.println(f(n));
	}
	static long f(int n) {
		if(memo[n] > 0) return memo[n];
		if(n <= 1) return memo[n] = 1;
		long ret = 1;
		for(int i=1; i<=n/2; i++) {
			ret += f(n - 2*i);
		}
		return memo[n] = ret;
	}
