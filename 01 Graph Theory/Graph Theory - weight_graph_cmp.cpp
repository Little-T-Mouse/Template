class edge{
public:
    int from;
    int to;
    int cost;
    int active;
    edge(){};
    edge(int from, int to, int cost, int active){
        this->from = from;
        this->to = to;
        this->cost = cost;
        this->active = active;
    };
};
bool cmp(edge a, edge b){
    if(a.cost==b.cost){
        return a.active < b.active;
    }
    return a.cost < b.cost;
}
