class Solution {
public:
void dijkstra(int i, unordered_map<int,vector<pair<int,int>>>map, vector<vector<int>>&adjmatrix)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,i});
    while(!pq.empty())
    {
        int dist=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto &it:map[node])
        {
            int edge=it.first;
            int cost=it.second;
            if(adjmatrix[i][edge]>dist+cost)
            {
                adjmatrix[i][edge]=dist+cost;
                pq.push({dist+cost,edge});
            }
        }
    }
}
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int,vector<pair<int,int>>>map;
        for(int i=0;i<edges.size();i++)
        {
            map[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            map[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<vector<int>>adjmatrix(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++)
        {
            dijkstra(i,map,adjmatrix);
        }
        int ans=-1;
        int mincount=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(i==j)
                continue;
                if(adjmatrix[i][j]<=distanceThreshold)
                {
                    count++;
                }
            }
            if(count<=mincount)
            {
                mincount=count;
                ans=i;
            }
        }
        return ans;
    }
};