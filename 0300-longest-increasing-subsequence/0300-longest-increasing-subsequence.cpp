class Solution {
public:
int solve(int start,vector<int>&nums,int prev,vector<vector<int>>&dp){

    if(start>=nums.size())
    return 0;
    int a=0,b=0;
    if(dp[start][prev+1]!=-1)
    return dp[start][prev+1];
    if(prev==-1 || nums[start]>nums[prev])
    {
        a= 1+solve(start+1,nums,start,dp);
    }
    b=solve(start+1,nums,prev,dp);
    return dp[start][prev+1]=max(a,b);
}
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return solve(0,nums,-1,dp);
    }
};