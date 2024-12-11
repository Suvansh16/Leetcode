class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int j=0,i=0;
        int countmax=0;
        int n=nums.size();
       while(i<n)
        {
            while(j<n && nums[j]<=nums[i]+2*k)
            {
                j++;
            }
            countmax=max(countmax,j-i);
            i++;

        }
        return countmax;
    }
};