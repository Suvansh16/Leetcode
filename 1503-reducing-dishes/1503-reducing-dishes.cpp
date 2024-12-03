class Solution {
public:
int solve(vector<int>&s, int start,int time,vector<vector<int>>&dp)
{
    if(start>=s.size())
    return 0;
    if(dp[start][time]!=-1)
    return dp[start][time];
    int take=s[start]*time+solve(s,start+1,time+1,dp);
    int nottake=solve(s,start+1,time,dp);
    return dp[start][time]=max(take,nottake);

}
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(satisfaction,0,1,dp);
    }
};