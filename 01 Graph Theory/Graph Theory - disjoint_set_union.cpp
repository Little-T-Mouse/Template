class dsu{
public:
    int* parent;
    int* ranks;
    int n;
    mst(int N){
        parent = new int[N+1];
        ranks = new int[N+1];
        n = N;
        init();
    }
    void init(){
        for(int i=0; i<=n; i++){
            parent[i] = i;
            ranks[i] = 0;
        }
    }
    int find_parent(int node){
        if(parent[node] != node)
            return parent[node] = find_parent(parent[node]);
        return parent[node];
    }
    bool same_parent(int a, int b){
        return find_parent(a) == find_parent(b);
    }
    void union_parent(int a, int b){
        int parent_a = find_parent(a), parent_b = find_parent(b);
        if(parent_a == parent_b) return; // Same tree
        else if(ranks[parent_a]<ranks[parent_b]){ // B is deeper
            parent[parent_a] = parent_b;
        }
        else if(ranks[parent_b]<ranks[parent_a]){ // A is deeper
            parent[parent_b] = parent_a;
        }
        else{ // Same deep
            parent[parent_b] = parent_a;
            ranks[parent_a]++;
        }
    }
};
