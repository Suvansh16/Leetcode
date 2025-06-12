class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            if(i==nums.size()-1)
            maxi=max(maxi,abs(nums[i]-nums[0]));
            else
            maxi=max(maxi,abs(nums[i]-nums[i+1]));
        }
        return maxi;
    }
};