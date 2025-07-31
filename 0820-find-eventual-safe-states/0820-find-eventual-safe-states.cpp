class Solution {
public:
bool dfs(int start,unordered_map<int,vector<int>>&map,vector<bool>&visited,vector<bool>&inrecursion)
{
    visited[start]=true;
    inrecursion[start]=true;
    for(int i=0;i<map[start].size();i++)
    {
        if(!visited[map[start][i]] && dfs(map[start][i],map,visited,inrecursion))
        return true;
        if(inrecursion[map[start][i]])
        return  true;
    }
    inrecursion[start]=false;
    return false;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool>visited(n,false);
        vector<bool>inrecursion(n,false);
        unordered_map<int,vector<int>>map;

        for(int i=0;i<n;i++)
        {
            vector<int>m=graph[i];
            for(int j=0;j<m.size();j++)
            map[i].push_back(m[j]);
        }
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(i,map,visited,inrecursion);
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(inrecursion[i]==false)
            ans.push_back(i);
        }
        return ans;
    }
};