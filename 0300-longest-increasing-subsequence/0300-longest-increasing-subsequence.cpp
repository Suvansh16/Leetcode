class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>parent(n,-1);
        int LIS=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i-1;j++)
            {
                if(nums[i]>nums[j] && dp[i]<(dp[j]+1))
                {
                    dp[i]=dp[j]+1;
                    LIS=max(LIS,dp[i]);
                    parent[i]=j;
                }
            }
        }
        //find the LIS index
        int ind=-1;
        vector<int>result;
        for(int i=0;i<n;i++)
        {
            if(dp[i]==LIS)
            ind=i;
        }
        while(ind!=-1)
        {
            result.push_back(nums[ind]);
            ind=parent[ind];
        }
        reverse(result.begin(),result.end());
        for(int i:result)
        cout<<i<<" ";
        return LIS;
    }
};