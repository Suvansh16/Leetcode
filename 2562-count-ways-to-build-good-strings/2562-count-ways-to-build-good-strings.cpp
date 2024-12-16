class Solution {
public:
int l,h,z,o;
const int mod=1e9+7;
int solve(int len,vector<int>&dp)
{
    if(len>h)
    return 0;
    if(dp[len]!=-1)
    return dp[len];
    int add=0;
    if(len>=l && len<=h)
    add=1;
    int m=solve(len+z,dp)%mod;
    int n=solve(len+o,dp)%mod;
    return dp[len]=(add+m+n)%mod;
}
    int countGoodStrings(int low, int high, int zero, int one) {
        l=low;
        h=high;
        z=zero;
        o=one;
        vector<int>dp(1e5+1,-1);
        return solve(0,dp);
    }
};