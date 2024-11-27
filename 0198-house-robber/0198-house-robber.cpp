class Solution {
public:
int n;
    int rob(vector<int>& nums) {
      n=nums.size();
        vector<int>dp(n+1,0);
        dp[0]=nums[0];
        dp[1]=nums[0];
        for(int i=2;i<=n;i++)
        {
            int skip=dp[i-1];
            int steal=nums[i-1]+dp[i-2];
            dp[i]=max(steal,skip);
        }
        return dp[n];
    }
};