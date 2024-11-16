class Solution {
public:
typedef long long ll;
typedef pair<int,int> p;
const int large_value=2e9;
ll dijkstra(vector<vector<int>>&edges,int n,int source,int destination)
{
    //make the graph excluding -1 edges
    unordered_map<int,vector<pair<int,int>>>adj;
    for(vector<int>&edge:edges)
    {
        if(edge[2]!=-1)
        {
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]});
        }
    }
    priority_queue<p,vector<p>,greater<p>>pq;
    vector<ll>result(n,INT_MAX);//result[i] is the shortest path dist from src to ith node
    result[source]=0;//src to src distance is 0
    pq.push({0,source});
    while(!pq.empty())
    {
        ll currdist=pq.top().first;
        ll currnode=pq.top().second;
        pq.pop();

        for(auto &[nbr,wt]:adj[currnode])
        {
            if(result[nbr]>currdist+wt)
            {
                result[nbr]=currdist+wt;
                pq.push({result[nbr],nbr});
            }
        }
    }
    return result[destination];
}
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        ll curr_shortest_path=dijkstra(edges,n,source,destination);
        if(curr_shortest_path<target)
        return {};
        else if(curr_shortest_path==target)
        {
            for(vector<int>&edge:edges)
            {
                if(edge[2]==-1)
                edge[2]=large_value;
            }
            return edges;
        }
       
            bool matchedtarget=(curr_shortest_path==target);
             for(vector<int>&edge:edges)
            {
                if(edge[2]==-1)
                {
                    edge[2]=(matchedtarget==true)?large_value:1;
                    if(matchedtarget!=true)
                    {
                        ll new_shortest_dist=dijkstra(edges,n,source,destination);
                        if(new_shortest_dist<=target)
                        {
                            matchedtarget=true;
                            edge[2]+=(target-new_shortest_dist);
                        }
                    }

                }
            }
        if(matchedtarget==false)
        return {};
        return edges;

    }
};