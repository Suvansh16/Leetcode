class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long sum=accumulate(nums.begin(),nums.end(),0);
       for(int i=n-1;i>=0;i--)
       {
        sum-=nums[i];
        if(sum%2==0)
        {
            int idx=lower_bound(nums.begin(),nums.end(),sum/2)-nums.begin();
            if(idx<n && idx!=i && nums[idx]==sum/2)
            return nums[i];
        }
        sum+=nums[i];
       }
       return -1;
    }
};