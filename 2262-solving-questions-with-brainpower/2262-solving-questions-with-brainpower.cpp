class Solution {
public:
int n;
long long  dp[100001];
long long solve(vector<vector<int>>& questions,int idx)
{
    if(idx>=n)
    return 0;
    if(dp[idx]!=-1)
    return dp[idx];
    long long ans=0;
    long long nottake=solve(questions,idx+1);
    long long take=questions[idx][0]+solve(questions,idx+questions[idx][1]+1);
    ans=max(take,nottake);
    return dp[idx]=ans;
}
    long long mostPoints(vector<vector<int>>& questions) {
        n=questions.size();
       memset(dp,-1,sizeof(dp));
       return  solve(questions,0);
    }
};