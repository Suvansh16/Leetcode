class Solution {
public:
bool dfs(unordered_map<int,vector<int>>&adj,int a,int b, vector<bool>&visited)
{
    if(a==b)
    return true;
    visited[a]=true;
    for(int &i:adj[a])
    {
        if(!visited[i])
        {
            if(dfs(adj,i,b,visited))
            return true;
        }

    }
    return false;
}

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        unordered_map<int,vector<int>>adj;
        for(vector<int>&e:edges)
        {
            int a=e[0];
            int b=e[1];
            vector<bool>visited(n+1,false);
            if(adj.find(a)!=adj.end() && adj.find(b)!=adj.end() && dfs(adj,a,b,visited))
            return e; 
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        return {};
    }
};