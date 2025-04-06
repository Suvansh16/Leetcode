class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>dp(nums.size(),1),prev(nums.size(),-1);
        int maxi=0;
        for(int i=1;i<nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                    prev[i]=j;
                }
            }
            if(dp[maxi]<dp[i])
            maxi=i;
        }
        vector<int>ans;
        for(int i=maxi;i>=0;i=prev[i])
        {
            ans.push_back(nums[i]);
        }
        return ans;
    }
};