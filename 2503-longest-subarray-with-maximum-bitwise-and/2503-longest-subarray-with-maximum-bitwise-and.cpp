class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int a=*max_element(nums.begin(),nums.end());
        int count=0;
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==a)
            {
                count++;
                res=max(count,res);
            }
            else
            {
                count=0;
            }

        }
        return res;
    }
};