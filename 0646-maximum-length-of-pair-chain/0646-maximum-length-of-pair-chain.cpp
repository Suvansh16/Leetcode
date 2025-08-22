class Solution {
public:
int dp[1001][1002];
int solve(int start,vector<vector<int>>&pairs,int prev)
{
    if(start>=pairs.size())
    return 0;
   if(dp[start][prev+1]!=-1)
   return dp[start][prev+1];
    int take=0,not_take=0;
    if(prev==-1 ||  pairs[prev][1]<pairs[start][0])
    {
        take=1+solve(start+1,pairs,start);
    }
    not_take=solve(start+1,pairs,prev);
    return dp[start][prev+1]=max(take,not_take);
    
}
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        memset(dp,-1,sizeof(dp));
        return solve(0,pairs,-1);
    }
};