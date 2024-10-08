class Solution {
public:

int solve(vector<int>&coins,int amount,vector<int>&dp)
{
    if(amount<0)
    return INT_MAX;
    if(amount==0)
    return 0;
    if(dp[amount]!=-1)
    return dp[amount];
    int ans=INT_MAX;
    for(int i=0;i<coins.size();i++)
    {
        int a=solve(coins,amount-coins[i],dp);
        if(a!=INT_MAX)
        {
            ans=min(ans,a+1);
        }
    }
    return dp[amount]=ans;
}
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int val=solve(coins,amount,dp);
        return val==INT_MAX?-1:val;
    }
};