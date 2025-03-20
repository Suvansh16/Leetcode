class Solution {
public:
bool bfs(unordered_map<int,vector<int>>&adj,int a,int b, vector<bool>&visited)
{
 queue<int>q;
 q.push(a);
 while(!q.empty())
 {
    int curr=q.front();
    q.pop();
    visited[curr]=true;
    if(curr==b)
    return true;
    for(int &i:adj[curr])
    {
        if(!visited[i])
        q.push(i);

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
            if(adj.find(a)!=adj.end() && adj.find(b)!=adj.end() && bfs(adj,a,b,visited))
            return e; 
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        return {};
    }
};