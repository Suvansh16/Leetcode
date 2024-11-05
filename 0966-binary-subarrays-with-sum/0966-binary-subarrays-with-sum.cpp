class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            int sum=nums[i];
            if(sum==goal)
            count++;
            for(int j=i+1;j<nums.size();j++)
            {
                sum+=nums[j];
                if(sum==goal)
                count++;
                else if(sum>goal)
                break;
                
            }
        }
        return count;
    }
};