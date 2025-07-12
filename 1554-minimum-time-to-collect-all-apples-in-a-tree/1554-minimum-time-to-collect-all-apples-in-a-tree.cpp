class Solution {
public:
int solve(int start,vector<bool>&hasapple,unordered_map<int,vector<int>>&map,int parent)
{
    int time=0;
    for(int i:map[start])
    {
        if(i!=parent)
        {
            int t=solve(i,hasapple,map,start);
            if(t>0 || hasapple[i])
            {
                time+=2+t;
            }
        }
    }
    return time;
}
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int,vector<int>>map;
        for(int i=0;i<edges.size();i++)
        {
            map[edges[i][0]].push_back(edges[i][1]);
            map[edges[i][1]].push_back(edges[i][0]);
        }
        return solve(0,hasApple,map,-1);
    }
};