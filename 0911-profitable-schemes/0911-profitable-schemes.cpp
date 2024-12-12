class Solution {
public:
const int mod=1e9+7;
int dp[101][101][101];
int solve(int n,int minprofit,vector<pair<int,int>>&gp,int start,int profit)
{
    if(start>=gp.size() && profit>=minprofit)
    return 1;
      if(start>=gp.size() && profit<minprofit)
    return 0;
    if(dp[n][start][profit]!=-1)
    return dp[n][start][profit];
    int take=0,nottake=0;
    if(n>=gp[start].first)
    take=solve(n-gp[start].first,minprofit,gp,start+1,min(minprofit,profit+gp[start].second));
    nottake=solve(n,minprofit,gp,start+1,profit);
    return dp[n][start][profit]=(take%mod+nottake%mod)%mod;
}
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<pair<int,int>>gp;
        for(int i=0;i<group.size();i++)
        {
            gp.push_back({group[i],profit[i]});
        }
        sort(gp.begin(),gp.end());
        memset(dp,-1,sizeof(dp));
       return  solve(n,minProfit,gp,0,0);
    }
};