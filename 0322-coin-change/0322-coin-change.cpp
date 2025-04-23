class Solution {
public:
int solve(int start,int amount,vector<int>&coins,vector<vector<int>>&dp)
{
    if(amount==0)
    return 0;
    if(start>=coins.size() || amount<0)
    return INT_MAX;
    if(dp[start][amount]!=-1)
    return dp[start][amount];
    int take=INT_MAX,nottake=INT_MAX;
    nottake=solve(start+1,amount,coins,dp);
    if(solve(start,amount-coins[start],coins,dp)!=INT_MAX)
    {
        take=1+solve(start,amount-coins[start],coins,dp);
    }
    return dp[start][amount]=min(take,nottake);
}
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
       int val=solve(0,amount,coins,dp);
        if(val==INT_MAX)
        return -1;
        return val;
    }
};