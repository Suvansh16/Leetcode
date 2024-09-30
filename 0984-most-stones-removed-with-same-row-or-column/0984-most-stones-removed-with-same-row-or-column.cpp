class Solution {
public:
int n;
void dfs(vector<vector<int>>&stones,int index,vector<bool>&visited)
{
    visited[index]=true;
    for(int i=0;i<n;i++)
    {
        int r=stones[index][0];
        int s=stones[index][1];
        if(visited[i]==false && (r==stones[i][0] || s==stones[i][1]))
        {
            dfs(stones,i,visited);
        }
    }
}
    int removeStones(vector<vector<int>>& stones) {
        int group=0;
        n=stones.size();
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==true)
            continue;
            dfs(stones,i,vis);
            group++;
        }
        return n-group;
    }
};