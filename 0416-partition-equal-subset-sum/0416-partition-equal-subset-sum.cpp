class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total_sum=accumulate(nums.begin(),nums.end(),0);
        if(total_sum%2!=0)
        return false;
        int a=total_sum/2;
        vector<vector<bool>>dp(nums.size()+1,vector<bool>(a+1,false));
         for (int i = 0; i <= nums.size(); ++i) {
        dp[i][0] = true;
    }
        for(int i=1;i<=nums.size();i++)
        {
            for(int j=1;j<=a;j++)
            {
                if(j<nums[i-1])
                dp[i][j]=dp[i-1][j];
                else
                dp[i][j]=dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }
        return dp[nums.size()][a];

    }
};