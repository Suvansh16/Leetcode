class Solution {
public:
bool dfs(unordered_map<int,vector<int>>&map,int curr,int currcolor,vector<int>&color)
{
    color[curr]=currcolor;
    for(auto &i:map[curr])
    {
        if(color[i]==currcolor)
        {
            return false;
        }
        if(color[i]==-1)
        {
            int colori=1-currcolor;
            if(dfs(map,i,colori,color)==false)
            return false;
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        unordered_map<int,vector<int>>map;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                map[i].push_back(graph[i][j]);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(dfs(map,i,1,color)==false)
                return false;
            }
        }
        return true;
    }
};