class Solution {
public:
int dp[2502][2502];
int solve(int start,int prev,vector<int>&nums)
{
    if(start>=nums.size())
    return 0;
    if(dp[start][prev+1]!=-1)
    return dp[start][prev+1];
    int max1=0,max2=0;
    if(prev<0 ||  nums[start]>nums[prev])
    max1=1+solve(start+1,start,nums);
    max2=solve(start+1,prev,nums);
    return dp[start][prev+1]=max(max1,max2);
}
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,-1,nums);
    }
};