class Solution {
public:
int m,n;
vector<int>directions{-1,0,1};
int DFS(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&dp)
{
    if(dp[row][col]!=-1)
    return dp[row][col];
    int moves=0;
    for(int &dir:directions)
    {
        int newrow=row+dir;
        int newcol=col+1;
        if(newrow>=0 && newcol>=0 && newrow<m && newcol<n && grid[newrow][newcol]>grid[row][col])
        {
            moves=max(moves,1+DFS(newrow,newcol,grid,dp));
        }
    }
    return dp[row][col]=moves;
}
    int maxMoves(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int result=0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++)
        {
            result=max(result,DFS(i,0,grid,dp));
        }
        return result;
    }
};