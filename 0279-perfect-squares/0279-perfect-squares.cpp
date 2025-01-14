class Solution {
public:
int minans;
int solve(int n,vector<int>&dp)
{
    if(n==0)
    return 0;
    if(n<0)
    return INT_MAX;
    if(dp[n]!=-1)
    return dp[n];
    int ans=INT_MAX;
    for(int i=1;i*i<=n;i++)
    {
         ans=min(ans,1+solve(n-i*i,dp));
    }
    return dp[n]=ans;

}
    int numSquares(int n) {
        minans=INT_MAX;
        vector<int>dp(n+1,-1);
        int a=solve(n,dp);
        return a;
    }
};