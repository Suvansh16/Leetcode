class Solution {
public:
int solve(vector<int>&nums,int target,int start,int sum)
{
    if(start>=nums.size())
    {
        if(sum==target)
        return 1;
        return 0;
    }
    int takep=solve(nums,target,start+1,sum+nums[start]);
    int takem=solve(nums,target,start+1,sum-nums[start]);
    return takep+takem;

}
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,target,0,0);
    }
};