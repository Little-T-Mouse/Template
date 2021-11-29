fill(dis, dis+MM, 1e9); dis[1] = 0;
for(int k=1; k<=n; k++){
double mi = 1e9; int u = -1;
for(int i=1; i<=n; i++)
   if(!vis[i] && dis[i] < mi) { mi = dis[i]; u = i; }
   if(u == -1) break;
   vis[u] = true;
   for(int v=1; v<=n; v++){
      if(!vis[v] && adj[u][v]<dis[v]) dis[v] = adj[u][v];
   }
}
