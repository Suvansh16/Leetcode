class Solution {
public:
vector<vector<int>>directions={{-1,0},{0,1},{0,-1},{1,0}};
int solve(int i,int j,vector<vector<int>>&grid,vector<vector<bool>>&visited)
{
   
    if(i>=grid.size() || i<0 || j<0 || j>=grid[0].size())
    return 0;
     if(visited[i][j] || grid[i][j]==0)
    return 0;
    visited[i][j]=true;
    int ans=1;
    for(auto &dir:directions)
    {
        int new_i=i+dir[0];
        int new_j=j+dir[1];
        ans+=solve(new_i,new_j,grid,visited);
        
    }
    return ans;
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]==false && grid[i][j]==1)
                {
                    int t=solve(i,j,grid,visited);
                    ans=max(ans,t);
                }
            }
        }
        return ans;
    }
};