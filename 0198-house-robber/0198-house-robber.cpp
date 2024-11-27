class Solution {
public:
int n;
int solve(vector<int>&nums,int start,vector<int>&dp)
{
    if(start>=n)
    return 0;
    if(dp[start]!=-1)
    return dp[start];
    int take=nums[start]+solve(nums,start+2,dp);
    int nottake=solve(nums,start+1,dp);
    return dp[start]=max(take,nottake);
}
    int rob(vector<int>& nums) {
        n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(nums,0,dp);
    }
};