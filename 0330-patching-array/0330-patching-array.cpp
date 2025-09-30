class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long mincount=0;
        int i=0;
        int patch=0;
        while(mincount<n)
        {
            if(i<nums.size() && mincount+1>=nums[i])
            {
                mincount+=nums[i];
                i++;
            }
            else
            {
                mincount+=mincount+1;
                patch++;
            }
        }
        return patch;
    }
};