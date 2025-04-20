class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>node(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++)
        node[i][i]=0;

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            node[u][v] = w;
            node[v][u] = w; // Since the graph is undirected
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(node[i][k]!=INT_MAX && node[k][j]!=INT_MAX)
                    node[i][j]=min(node[i][j],node[i][k]+node[k][j]);

                }
            }
        }
        int mincount=INT_MAX;
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    if(node[i][j]<=distanceThreshold)
                    {
                        count++;
                    }
                }
            }
            if(mincount>=count)
            {
                mincount=count;
                ans=i;
            }
        }
        return ans;
    }
};