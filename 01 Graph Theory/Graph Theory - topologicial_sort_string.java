	public static void main(String[] args) throws IOException{
		int M = readInt(); int indegree[] = new int[M*2]; String name[] = new String[M*2];
		HashMap<String, Integer> dic = new HashMap<String,Integer>();
		ArrayList<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>();
		int cnt = 0;
		for(int i = 0; i < M*2; i++) graph.add(new ArrayList<Integer>());
		for(int i=0; i<M; i++) {
			String A = next(), B = next();
			if(!dic.containsKey(A)) {
				dic.put(A, cnt); name[cnt] = A; cnt++; 
			}
			if(!dic.containsKey(B)) {
				dic.put(B, cnt); name[cnt] = B; cnt++; 
			}
			graph.get(dic.get(B)).add(dic.get(A)); indegree[dic.get(A)]++;
		}
		int N = cnt;
		while(true) {
			cnt = -1;
			for(int i=0; i<N; i++) {
				if(indegree[i]==0) {
					indegree[i]--; cnt=i; break;
				}
			}
			if(cnt == -1) break;
			System.out.println(name[cnt]);
			for(int nxt: graph.get(cnt)) indegree[nxt]--;
		}
 }
