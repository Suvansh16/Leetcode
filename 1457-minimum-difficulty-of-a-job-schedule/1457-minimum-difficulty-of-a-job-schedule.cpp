class Solution {
public:
int n;
int solve(int idx,vector<int>&job,int d,vector<vector<int>>&dp)
{
    if(d==1)
    {
        //you have to perform all the task in the same day
        int maxans=job[idx];
        for(int i=idx;i<n;i++)
        {
            maxans=max(maxans,job[i]);
        }
        return maxans;
    }
    if(dp[idx][d]!=-1)
    return dp[idx][d];
    int maximum=job[idx];
    int ans=INT_MAX;
    //pehle wale me kitne elements ko include kar sakte
    for(int i=idx;i<=n-d;i++)
    {
        maximum=max(maximum,job[i]);
        int cal_ahead=maximum+solve(i+1,job,d-1,dp);
        ans=min(ans,cal_ahead);
    }
    return dp[idx][d]=ans;

}
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        n=jobDifficulty.size();
        if(d>n)
        return -1;
        vector<vector<int>>dp(n+1,vector<int>(d+1,-1));
        return solve(0,jobDifficulty,d,dp);
    }
};