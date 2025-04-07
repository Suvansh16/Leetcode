class Solution {
public:
bool solve(int start,int sum,vector<int>&nums,vector<vector<int>>&dp)
{
     if(start>=nums.size() ||  sum<0)
    return false;
    if(sum==0)
    return true;
   if(dp[start][sum]!=-1)
   return dp[start][sum];
    bool a=solve(start+1,sum,nums,dp);
    bool b=solve(start+1,sum-nums[start],nums,dp);
    return dp[start][sum]=a|| b;
}
    bool canPartition(vector<int>& nums) {
        int total_sum=accumulate(nums.begin(),nums.end(),0);
        if(total_sum%2!=0)
        return false;
        int a=total_sum/2;
        vector<vector<int>>dp(nums.size(),vector<int>(a+1,-1));
        return solve(0,total_sum/2,nums,dp);

    }
};