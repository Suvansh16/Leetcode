class Solution {
public:
bool solve(int start,int c,vector<int>&color,unordered_map<int,vector<int>>&map)
{
    color[start]=c;
    for(int i:map[start])
    {
        if(color[i]==c)
        return false;
        if(color[i]==-1)
        {
            bool t=solve(i,1-c,color,map);
            if(!t)
            return false;
        }
    }
    return true;

}
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>color(n+1,-1);
        unordered_map<int,vector<int>>map;
        for(int i=0;i<dislikes.size();i++)
        {
            map[dislikes[i][0]].push_back(dislikes[i][1]);
            map[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        for(int i=1;i<=n;i++)
        {
            if(color[i]==-1)
            {
                bool t=solve(i,0,color,map);
                if(t==false)
                return false;
            }
        }
        return true;
    }
};