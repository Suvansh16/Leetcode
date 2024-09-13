class Solution {
public:
int n,m;
int solve(int start,int end,vector<vector<int>>&grid,vector<vector<int>>&dp)
{
    if(start==n && end==m)
    return grid[start][end];
    if(start>n || end>m)
    return INT_MAX;
    if(dp[start][end]!=-1)
    return dp[start][end];
    int down=solve(start+1,end,grid,dp);
    int right=solve(start,end+1,grid,dp);
    int val1,val2;
    if(down!=INT_MAX)
    val1=grid[start][end]+down;
    else
    val1=INT_MAX;
    if(right!=INT_MAX)
    val2=grid[start][end]+right;
    else
    val2=INT_MAX;
    return dp[start][end]=min(val1,val2);    
}
    int minPathSum(vector<vector<int>>& grid) {
        n=grid.size()-1;
        m=grid[0].size()-1;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,grid,dp);
    }
};