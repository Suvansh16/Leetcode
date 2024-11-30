class Solution {
public:
int solve(int start,vector<int>&prices,int stock,vector<vector<int>>&dp)
{
    if(start>=prices.size())
    return 0;
    if(dp[start][stock]!=-1)
    return dp[start][stock];
    int profit=INT_MIN;
    int sell,skip_sell,take,skip_take;
    if(stock)
    {
        sell=prices[start]+solve(start+2,prices,0,dp);
        skip_sell=solve(start+1,prices,1,dp);
        profit=max(sell,skip_sell);
    }

    else
    {
        take=solve(start+1,prices,1,dp)-prices[start];
        skip_take=solve(start+1,prices,0,dp);
        profit=max(take,skip_take);
    }

    return dp[start][stock]=profit; 
}
    int maxProfit(vector<int>& prices) {
        int  stock=0;
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        return solve(0,prices,stock,dp);
    }
};