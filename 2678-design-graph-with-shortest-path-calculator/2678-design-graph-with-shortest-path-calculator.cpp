class Graph {
public:
unordered_map<int,vector<pair<int,int>>>map;
int size;
int dijkstra(int node1,int node2)
{
    vector<int>distances(size,INT_MAX);
    distances[node1]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
    pq.push({0,node1});
    while(!pq.empty())
    {
        int currnode=pq.top().second;
        int currdis=pq.top().first;
        pq.pop();
        if(currdis>distances[currnode])
        continue;
        if(currnode==node2)
        return currdis;
        for(auto i:map[currnode])
        {
            int neigh=i.first;
            int cost=i.second;
            int newrout=currdis+cost;
            if(distances[neigh]>newrout)
            {
                distances[neigh]=newrout;
                pq.push({newrout,neigh});
            }
        }
    }

    return distances[node2]==INT_MAX?-1:distances[node2];
}
    Graph(int n, vector<vector<int>>& edges) {
        for(auto i:edges)
        {
            map[i[0]].push_back({i[1],i[2]});
        }
        size=n;

    }
    
    void addEdge(vector<int> edge) {
        map[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        return dijkstra(node1,node2);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */