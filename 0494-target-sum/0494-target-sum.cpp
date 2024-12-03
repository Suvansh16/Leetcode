class Solution {
public:
int solve(vector<int>&nums,int target,int start,int ans)
{
    if(start>=nums.size() && ans!=target)
    {
        return 0;
    }
    if(start>=nums.size() && ans==target)
    return 1;
    int ans1=solve(nums,target,start+1,ans+nums[start]);
    int ans2=solve(nums,target,start+1,ans-nums[start]);
    return (ans1+ans2);
}
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,target,0,0);
    }
};