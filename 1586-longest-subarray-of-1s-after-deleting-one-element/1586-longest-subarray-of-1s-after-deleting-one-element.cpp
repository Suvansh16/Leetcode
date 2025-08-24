class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int>a;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            a.push_back(i);
        }
        if(a.empty())
        return nums.size()-1;
        int prev=a[0];
        int ans=0;
        for(int i=1;i<a.size();i++)
        {
            int t=a[i]-a[i-1]-1;
            ans=max(ans,t+prev);
            prev=t;

        }
        int l=nums.size()-a[a.size()-1]-1;
        ans=max(ans,l+prev);
        return ans;
    }
};