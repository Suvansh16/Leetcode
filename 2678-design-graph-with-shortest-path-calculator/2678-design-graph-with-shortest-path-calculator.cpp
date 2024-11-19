class Graph {
public:
void floyd_warshall(unordered_map<int,vector<pair<int,int>>>&map,vector<vector<int>>&a,int n)
{
    for(auto i:map)
    {
       for(auto j:map[i.first])
       {
        a[i.first][j.first]=min(j.second,a[i.first][j.first]);
       }
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][k]==INT_MAX || a[k][j]==INT_MAX)
                continue;
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
}
  vector<vector<int>>adj_matrix;
  unordered_map<int,vector<pair<int,int>>>map;
  int size;
    Graph(int n, vector<vector<int>>& edges) {
        
        for(int i=0;i<edges.size();i++)
        {
            int a=edges[i][0];
            int b=edges[i][1];
            int c=edges[i][2];
            map[a].push_back({b,c});
            
        }
        size=n;
      adj_matrix.resize(n,vector<int>(n,INT_MAX));
       for (int i = 0; i < n; ++i) {
            adj_matrix[i][i] = 0; // Distance to itself is 0
        }
        floyd_warshall(map,adj_matrix,n);

    }
    
    void addEdge(vector<int> edge) {
        int a=edge[0];
        int b=edge[1];
        int c=edge[2];
        map[a].push_back({b,c});
      
         adj_matrix[a][b] = min(adj_matrix[a][b], c);
         floyd_warshall(map,adj_matrix,size);
    }
    
    int shortestPath(int node1, int node2) {
        int ans=0;

        return adj_matrix[node1][node2]==INT_MAX?-1:adj_matrix[node1][node2];

    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */