class Solution {
public:
vector<vector<int>>ans;
void solve(int start,int end,unordered_map<int,vector<int>>&map,vector<int>output)
{
    if(start==end)
    {
        output.push_back(start);
        ans.push_back(output);
        return ;

    }
    output.push_back(start);
    for(int i:map[start])
    {
        solve(i,end,map,output);
    }
    output.pop_back();
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        unordered_map<int,vector<int>>map;

        for(int i=0;i<graph.size();i++)
        {
            map[i]=graph[i];
        }
        solve(0,graph.size()-1,map,{});
        return ans;
    }
};