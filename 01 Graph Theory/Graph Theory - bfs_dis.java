static void bfs_dis(int start, int [] level) { // Get the distance from start to every reachble point
	    // Note: graph is a 2D array, n is the numbers of node
  	  boolean [] vis = new boolean [n+1]; LinkedList<Integer> que = new LinkedList<Integer>();
  	  que.add(start); vis[start] = true; 
  	  level[start] = 0;
  	  while(!que.isEmpty()) {
  		  int cur = que.poll();
  		  for(int next: graph.get(cur)) {
  			  if(!vis[next]) { que.add(next); vis[next] = true; level[next] = level[cur] + 1;}
  		  }
  	  }
}
