class Solution {
public:
int solve(int start,vector<bool>&visited,unordered_map<int,vector<int>>&map)
{
    visited[start]=true;
    int ans=1;
    for(int i:map[start])
    {

        if(!visited[i])
        {
            ans+=solve(i,visited,map);
        }
    }
    return ans;
}
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int,vector<int>>map;
        for(int i=0;i<stones.size();i++)
        {
            for(int j=i+1;j<stones.size();j++)
            {
                if(stones[j][0]==stones[i][0] || stones[j][1]==stones[i][1])
                {
                    map[i].push_back(j);
                    map[j].push_back(i);
                }
            }
        }
        vector<bool>visited(stones.size(),false);
        int count=0;
        vector<int>ans;
       for(int i=0;i<stones.size();i++)
       {
        
        if(!visited[i])
        {
            
            ans.push_back(solve(i,visited,map));
        }
       }
       int result=0;
       for(auto i:ans)
       result+=(i-1);
       return result;
    }
};