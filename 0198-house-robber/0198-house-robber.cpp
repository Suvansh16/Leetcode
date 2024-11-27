class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>t(nums.size()+1,0);
        t[0]=0;
        t[1]=nums[0];
        for(int i=2;i<=nums.size();i++)
        {
            int skip=t[i-1];
            int steal=nums[i-1]+t[i-2];
            t[i]=max(skip,steal);
        }
        return t[nums.size()];
    }
};