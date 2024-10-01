class Solution {
public:
bool dfs(int i,unordered_map<int,vector<int>>&map,int destination,vector<bool>&visited)
{
    if(i==destination)
    return true;
    visited[i]=true;
    for(auto j:map[i])
    {
        if(!visited[j])
        {
            if(dfs(j,map,destination,visited))
            return true;
        }
    }
    return false;

}
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
          unordered_map<int,vector<int>>map;
        for(vector<int>&edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            map[u].push_back(v);
            map[v].push_back(u);
        }
        vector<bool>visited(n,false);
        return dfs(source,map,destination,visited);
    }
};