class Solution {
public:
int n;int dp[50001];
int solve(int start,vector<int>&grid)
{
    if(start>=n)
    return 0;
    if(dp[start]!=-1)
    return dp[start];
    int result=INT_MIN;
    result=max(result,grid[start]-solve(start+1,grid));
    if(start+1<n)
    result=max(result,grid[start]+grid[start+1]-solve(start+2,grid));
    if(start+2<n)
    result=max(result,grid[start]+grid[start+1]+grid[start+2]-solve(start+3,grid));
    return dp[start]=result;
}
    string stoneGameIII(vector<int>& stoneValue) {
      n=stoneValue.size();
     memset(dp,-1,sizeof(dp));
      int ans=solve(0,stoneValue);
      if(ans>0)
      return "Alice";
      else if(ans<0)
      return "Bob";
      return "Tie";
    }
};