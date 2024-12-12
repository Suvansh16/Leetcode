class Solution {
public:
const int mod=1e9+7;

int solve(string s,int k,int idx,vector<long long>&dp)
{
    if(idx>=s.length())
    return 1;
    if(s[idx]=='0')
    return 0;
    if(dp[idx]!=-1)
    return dp[idx];
    long long ans=0;
    long long num=0;
    for(int i=idx;i<s.length();i++)
    {
        num=num*10+(s[i]-'0');
        if(num>k)
        break;
        ans=(ans%mod+solve(s,k,i+1,dp)%mod);
    }
    return dp[idx]=ans;

}
    int numberOfArrays(string s, int k) {
       vector<long long >dp(s.length()+1,-1);
        return solve(s,k,0,dp);
    }
};