class Solution {
public:
void dfs(int start,vector<bool>&visited,unordered_map<int,vector<int>>&map)
{
    visited[start]=true;
    for(int i:map[start])
    {
        if(!visited[i])
        {
            dfs(i,visited,map);
        }
    }
}
bool isSimilar(string a,string b)
{
    int count=0;
    if(a.length()!=b.length())
    return false;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=b[i])
        count++;
    }
    return count<=2?true:false;
}
    int numSimilarGroups(vector<string>& strs) {
        unordered_map<int,vector<int>>map;
        for(int i=0;i<strs.size();i++)
        {
            for(int j=i+1;j<strs.size();j++)
            {
                if(isSimilar(strs[i],strs[j]))
                {
                    map[i].push_back(j);
                    map[j].push_back(i);
                }
            }
        }
        vector<bool>visited(strs.size(),false);
        int count=0;
        for(int i=0;i<strs.size();i++)
        {
            if(!visited[i])
            {
                dfs(i,visited,map);
                count++;
            }
        }
        return count;

    }
};