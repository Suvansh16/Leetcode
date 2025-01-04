class Solution {
public:
const int mod=1e9+7;
int dp[101][201];
int solve(int start,int fuel,vector<int>&loc,int finish)
{
if(fuel<0)
return 0;
if(dp[start][fuel]!=-1)
return dp[start][fuel];
int ans=(start==finish)?1:0;
for(int i=0;i<loc.size();i++)
{
    if(i!=start)
    ans=(ans+(solve(i,fuel-abs(loc[start]-loc[i]),loc,finish))%mod)%mod;

}

return dp[start][fuel]=ans;
}
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
      memset(dp,-1,sizeof(dp));
        return solve(start,fuel,locations,finish);
    }
};