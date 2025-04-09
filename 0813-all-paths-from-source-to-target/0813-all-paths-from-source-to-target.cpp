class Solution {
public:
vector<vector<int>>ans;
void solve(int src,int dest,unordered_map<int,vector<int>>&map,vector<int>output,vector<int>&visited)
{
    if(src==dest)
    {
        ans.push_back(output);
        return ;
    }
    visited[src]=true;
    for(auto i:map[src])
    {
        if(visited[i])
        return;
        output.push_back(i);
        solve(i,dest,map,output,visited);
        output.pop_back();

    }
    visited[src]=false;

}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        unordered_map<int,vector<int>>map;
        int l=0;
        for(auto i:graph)
        {
            map[l]=(i);
            l++;
        }
        int dest=graph.size()-1;
        vector<int>output;
        vector<int>visited(dest+1,false);
        output.push_back(0);
        solve(0,dest,map,output,visited);
        return ans;
    }
};