class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        vector<int>temp=nums;
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=0;j<nums.size()-1-i;j++)
            {
                if(nums[j]>nums[j+1] && __builtin_popcount(nums[j])==__builtin_popcount(nums[j+1]))
                swap(nums[j],nums[j+1]);
            }
        }
        for(int i=0;i<nums.size();i++)
        cout<<nums[i]<<" ";
        sort(temp.begin(),temp.end());
        if(temp==nums)
        return true;
        return false;
    }
};