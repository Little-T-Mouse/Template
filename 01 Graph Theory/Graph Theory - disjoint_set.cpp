int find_parent(int node){
    if(node!=parent[node]){
        parent[node] = find_parent(parent[node]);
    }
    return parent[node];
}
bool same_parent(int a, int b){
    return find_parent(a)==find_parent(b);
}
void union_parent(int a, int b){
    int parent_a = find_parent(a);
    int parent_b = find_parent(b);
    if(parent_a==parent_b) return;
    else if(parent_a<parent_b){
        parent[parent_b] = parent_a;
        find_parent(b);
    }
    else{
        parent[parent_a] = parent_b;
        find_parent(a);
    }
}
