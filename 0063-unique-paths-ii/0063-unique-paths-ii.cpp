class Solution {
public:
vector<vector<int>>directions={{1,0},{0,1}};
int dp[101][101];
int solve(int i,int j,int end_i,int end_j,vector<vector<bool>>&visited,vector<vector<int>>&grid)
{
    if(i==end_i && j==end_j)
    return 1;
    if(dp[i][j]!=-1)
    return dp[i][j];
    visited[i][j]=true;
    int ans=0;
    for(vector<int>dir:directions)
    {
        int new_i=i+dir[0];
        int new_j=j+dir[1];
        if(new_i>=0 && new_j>=0 && new_i<=end_i && new_j<=end_j && !visited[new_i][new_j] && grid[new_i][new_j]==0)
        {
            if(solve(new_i,new_j,end_i,end_j,visited,grid))
            ans+=solve(new_i,new_j,end_i,end_j,visited,grid);

        }
    }
    visited[i][j]=false;
    return dp[i][j]=ans;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        if(obstacleGrid[0][0]==1)
        return 0;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,m-1,n-1,visited,obstacleGrid);        
    }
};