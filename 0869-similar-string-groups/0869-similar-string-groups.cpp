class Solution {
public:
void dfs(unordered_map<int,vector<int>>&map,vector<bool>&visited,int start)
{
    visited[start]=true;
    for(auto i:map[start])
    {
        if(!visited[i])
        {
            dfs(map,visited,i);
        }
    }
}
bool issimilar(string a,string b)
{
    int len=a.length();
    int i=0;
    int sum=0;
    while(i!=len)
    {
        if(a[i]!=b[i])
        sum++;
        i++;
    }
    return sum>2?false:true;
}
    int numSimilarGroups(vector<string>& strs) {
        unordered_map<int,vector<int>>map;
        for(int i=0;i<strs.size()-1;i++)
        {
            for(int j=i+1;j<strs.size();j++)
            {
                if(issimilar(strs[i],strs[j]))
                {
                    map[i].push_back(j);
                    map[j].push_back(i);
                }
            }
        }
        int count=0;
        vector<bool>visited(strs.size(),false);
        for(int i=0;i<strs.size();i++)
        {
        if(!visited[i]) {   
        count++;
        dfs(map,visited,i);
        }
        }
        return count;
    }
};