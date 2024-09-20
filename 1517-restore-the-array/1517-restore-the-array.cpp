class Solution {
public:
int mod=1e9+7;
int solve(int idx,string &s,int k,vector<int>&dp)
{
    if(idx>=s.length())
    return 1;
    if(s[idx]=='0')
    return dp[idx]=0;
    if(dp[idx]!=-1)
    return dp[idx];
    long long ans=0;
    long long num=0;
    for(int i=idx;i<s.length();i++)
    {
        num=num*10+(s[i]-'0');
        if(num>k)
        break;
        ans=(ans%mod+solve(i+1,s,k,dp)%mod)%mod;

    }
    return dp[idx]=ans;
}
    int numberOfArrays(string s, int k) {
        vector<int>dp(s.length(),-1);
        return solve(0,s,k,dp);
    }
};