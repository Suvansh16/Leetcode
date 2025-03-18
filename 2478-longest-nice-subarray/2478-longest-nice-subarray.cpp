class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int right=1;
        int left=0;
        int n=nums.size();
        int maxi=1;
        int mask=nums[0];
        while(right<n)
        {
            while((mask & nums[right])!=0)
            {
                mask^=nums[left++];//same as mask-=nums[left] and then left increment
            }
            mask=mask | nums[right];
            maxi=max(maxi,right-left+1);
            right++;
        }
        return maxi;
    }
};