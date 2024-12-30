class Solution {
public:
int l,h,z,o;
const int mod=1e9+7;
int solve(int length,vector<int>&dp)
{
    if(length>h)
    return 0;
    if(dp[length]!=-1)
    return dp[length];
    int add=0;
    if(length>=l && length<=h)
    add=1;
    int m=solve(length+o,dp);
    int n=solve(length+z,dp);
    return dp[length]=(add+m+n)%mod;

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