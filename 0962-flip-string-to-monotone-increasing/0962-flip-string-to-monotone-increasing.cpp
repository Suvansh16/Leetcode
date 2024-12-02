class Solution {
public:

int solve(string s,int start,int one,vector<vector<int>>&dp)
{
    if(start>=s.length())
    {
        return 0;
    }
    if(dp[start][one]!=-1)
    return dp[start][one];
    int flip,no_flip;
    flip=INT_MAX;
    no_flip=INT_MAX;
    if(s[start]=='1')
    {
        if(one==1)
        {
            no_flip=solve(s,start+1,one,dp);
        }
        else
        {
            flip=1+solve(s,start+1,0,dp);
            no_flip=solve(s,start+1,1,dp);
        }

    }
    else if(s[start]=='0')
    {
        if(one==true)
        {
            flip=1+solve(s,start+1,1,dp);
        }
        else
        {
            flip=1+solve(s,start+1,1,dp);
            no_flip=solve(s,start+1,0,dp);
        }
    }
    return dp[start][one]=min(flip,no_flip);
  


}
    int minFlipsMonoIncr(string s) {
        int start=0;
      
       int one=0;
        vector<vector<int>>dp(s.length()+1,vector<int>(2,-1));
       return solve(s,start,one,dp);
       
    }
};