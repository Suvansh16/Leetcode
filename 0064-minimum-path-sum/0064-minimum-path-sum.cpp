class Solution {
public:
vector<vector<int>>directions={{1,0},{0,1}};
int n,m;
int solve(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&dp)
{
     if(i<0 || j<0 || i>n ||j>m)
    return INT_MAX;

    if(i==n && j==m)
    return grid[n][m];
    
   
    if(dp[i][j]!=-1)
    return dp[i][j];

   int ans1=INT_MAX,ans2=INT_MAX;
   if(solve(grid,i+1,j,dp)!=INT_MAX)
   ans1=grid[i][j]+solve(grid,i+1,j,dp);
    if(solve(grid,i,j+1,dp)!=INT_MAX)
   ans2=grid[i][j]+solve(grid,i,j+1,dp);
   return dp[i][j]=min(ans1,ans2);
}
    int minPathSum(vector<vector<int>>& grid) {
        n=grid.size()-1;
        m=grid[0].size()-1;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(grid,0,0,dp);
    }
};