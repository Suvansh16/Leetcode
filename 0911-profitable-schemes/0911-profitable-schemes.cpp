class Solution {
public:
const int mod=1e9+7;
int dp[101][101][101];
int solve(int n,int minProfit,vector<int>&group,vector<int>&profit,int idx)
{
    if(idx>=profit.size())
    return minProfit<=0?1:0;
    if(dp[n][minProfit][idx]!=-1)
    return dp[n][minProfit][idx];
    int nottaken=solve(n,minProfit,group,profit,idx+1)%mod;
    int taken=0;
    if(n>=group[idx])
    taken=(solve(n-group[idx],max(0,minProfit-profit[idx]),group,profit,idx+1))%mod;
    return dp[n][minProfit][idx]=(taken+nottaken)%mod;

}
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
       return  solve(n,minProfit,group,profit,0);
    }
};