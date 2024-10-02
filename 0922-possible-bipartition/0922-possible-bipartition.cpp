class Solution {
public:
bool dfs(unordered_map<int,vector<int>>&map,int curr,vector<int>&color,int currcolor)
{
    color[curr]=currcolor;
    for(int &v:map[curr])
    {
        if(color[v]==currcolor)
        return false;
        if(color[v]==-1)
        {
            int colorv=1-color[curr];
            if(dfs(map,v,color,colorv)==false)
            return false;
        }
    }
    return true;
}
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>>map;
        for(vector<int>&v:dislikes)
        {
            map[v[0]].push_back(v[1]);
            map[v[1]].push_back(v[0]);
        }
        vector<int>color(n+1,-1);
        for(int i=1;i<=n;i++)
        {
           if(color[i]==-1)
           {
                bool ans= dfs(map,i,color,0);
                if(ans==false)
                return false;
            }
        }
        return true;
    }
};