class Solution {
public:
#include <algorithm>  // To use min()
#include <vector>     // To use vector
bool solve(vector<int>&nums,int start,vector<int>&dp)
{
    if(start>=nums.size())
    return false;
    if(start==nums.size()-1)
    return true;
    if(dp[start]!=-1)
    return dp[start];
    int a = min((int)nums.size()-1,start+nums[start]);
    for(int i=start+1;i<=a;i++)
    {
        if(solve(nums,i,dp))
        return dp[start]=true;
    }
    return dp[start]=false;
}
    bool canJump(vector<int>& nums) {
        int start=0;
        vector<int>dp(nums.size()+1,-1);
       return  solve(nums,start,dp);
    }
};