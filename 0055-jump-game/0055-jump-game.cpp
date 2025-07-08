class Solution {
public:
bool solve(int start,vector<int>&nums,vector<int>&dp)
{
    if(start>=nums.size()-1)
    return true;
    if(dp[start]!=-1)
    return dp[start];
    for(int i=start+1;i<=min((int)nums.size()-1,start+nums[start]);i++)
    {
         if(solve(i,nums,dp))
         return dp[i]=true;
    }
    return dp[start]=false;
}
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return solve(0,nums,dp);

    }
};