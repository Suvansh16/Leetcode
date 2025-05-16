class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int  n=nums.size();
        int LIS=1;
        vector<int>dp(n,1);
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<=i-1;j++)
            {
                if(nums[i]>nums[j])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                    LIS=max(LIS,dp[i]);
                }
            }
        }
        return LIS;

    }
};