class Solution {
public:
bool dfs(unordered_map<int,vector<int>>&map,int start,vector<bool>&visited,vector<bool>&inrecursion)
{
    visited[start]=true;
    inrecursion[start]=true;
    for(int i:map[start])
    {
        if(visited[i]==false && dfs(map,i,visited,inrecursion))
        return true;
        if(inrecursion[i])
        return true;
    }
    inrecursion[start]=false;
    return false;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int,vector<int>>map;
     
        for(int i=0;i<graph.size();i++)
        {
            vector<int>a=graph[i];
           
            for(auto j:a)
            map[i].push_back(j);
        }
       vector<bool>visited(graph.size(),false);
       vector<bool>inrecursion(graph.size(),false);
       for(int i=0;i<graph.size();i++)
       {
        if(!visited[i])
        {
            dfs(map,i,visited,inrecursion);
        }
       }
       vector<int>ans;
       for(int i=0;i<graph.size();i++)
       {
        if(inrecursion[i]==false)
        {
            ans.push_back(i);
        }
       }
       return ans;

    }
};