class Solution {
public:
const int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto road:roads)
        {
            adj[road[0]].push_back({road[1],road[2]});
            adj[road[1]].push_back({road[0],road[2]});
        }
        priority_queue<pair<long long ,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        vector<long long>dist(n,LLONG_MAX);
        vector<int>ways(n,0);
        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;
        while(!pq.empty())
        {
            auto [currdist,node]=pq.top();
            pq.pop();
            if(currdist>dist[node])
            continue;
            for(auto & [neighbour,weight]:adj[node])
            {
                long long newdist=currdist+weight;
                if(newdist<dist[neighbour])
                {
                    dist[neighbour]=newdist;
                    ways[neighbour]=ways[node];
                    pq.push({newdist,neighbour});
                }
                else if(newdist==dist[neighbour])
                ways[neighbour]=(ways[node]+ways[neighbour])%mod;
            }
        }
        return ways[n-1];

    }
};