class Solution {
public:
int solve(string &s,int ind,int  prev,int n,vector<vector<int>>&dp)
{
    if(ind>=n)
    return 0;
    if(dp[ind][prev]!=-1)
    return dp[ind][prev];
    int flip,noflip;
    flip=INT_MAX;
    noflip=INT_MAX;
    if(s[ind]=='1')
    {
        if(prev==1)
        {
            noflip=solve(s,ind+1,1,n,dp);
        }
        else
        {
            flip=1+solve(s,ind+1,0,n,dp);
            noflip=solve(s,ind+1,1,n,dp);
        }
    }
    else if(s[ind]=='0')
    {
        if(prev==0)
        {
            flip=1+solve(s,ind+1,1,n,dp);
            noflip=solve(s,ind+1,0,n,dp);
        }
        else
        {
            flip=1+solve(s,ind+1,1,n,dp);
        }
    }
    return dp[ind][prev]=min(flip,noflip);
}
    int minFlipsMonoIncr(string s) {
       int  n=s.length();
        vector<vector<int>>t(n+1,vector<int>(2,-1));
        return solve(s,0,0,n,t);
    }
};