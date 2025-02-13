class Solution {
public:
    bool check(vector<int>& nums) {
        //if there are more than two inversions than it will not be in sorted order;
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]>nums[(i+1)%n] && ++count>1)
            return false;
        }
        return true;
    }
};