class Solution {
public:

bool solve(vector<bool>&visited,vector<bool>&inrecursion,vector<int>&ans,int val,unordered_map<int,vector<int>>&map)
{
    visited[val]=true;
    inrecursion[val]=true;
    for(auto i:map[val])
    {
        if(!visited[i])
        {
            if(!solve(visited,inrecursion,ans,i,map))
            return false;
        }
        else if(inrecursion[i])
        return false;

    }
    ans.push_back(val);
    inrecursion[val]=false;
    return true;
}

vector<int>topologicalsort( vector<vector<int>>& v,int k)
{
    unordered_map<int,vector<int>>map;
    for(vector<int>&i:v)
    {
       map[i[0]].push_back(i[1]);
    }
    vector<int>ans;
    vector<bool>visited(k+1,false);
    vector<bool>inrecursion(k+1,false);
    for(int i=1;i<=k;i++)
    {
        if(!visited[i])
        {
            if(!solve(visited,inrecursion,ans,i,map))
            return {};
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int>rowcond=topologicalsort(rowConditions,k);
        vector<int>colcond=topologicalsort(colConditions,k);
        if(rowcond.empty() || colcond.empty())
        return {};
        unordered_map<int,int>rowpos;
        unordered_map<int,int>colpos;
        for(int i=0;i<k;i++)
        {
            rowpos[rowcond[i]]=i;
            colpos[colcond[i]]=i;
        }
        vector<vector<int>>result(k,vector<int>(k,0));
        for(int i=1;i<=k;i++)
        {
            result[rowpos[i]][colpos[i]]=i;
        }
        return result;
    }
};