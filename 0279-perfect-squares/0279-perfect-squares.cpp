class Solution {
public:
int solve(int n,int t,vector<int>&dp)
{
    if(n<0)
    return INT_MAX;
    if(n==0)
    return 0;
    if(dp[n]!=-1)
    return dp[n];
    int ans=INT_MAX;
    for(int i=1;i<=t;i++)
    {
        int m=solve(n-i*i,t,dp);
        if(m!=INT_MAX)
        ans=min(ans,1+m);
    }
    return dp[n]=ans;
}
    int numSquares(int n) {
        int t =sqrt(n);
        vector<int>dp(n+1,-1);
        return solve(n,t,dp);
    }
};