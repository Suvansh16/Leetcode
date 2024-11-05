class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i=0,j=0;
        int sum=0;
        int n=nums.size();
        int count=0;
        int count_zero=0;
        while(j<n)
        {
            sum+=nums[j];
            
            while(i<j && (sum>goal || nums[i]==0))
            {
                if(nums[i]==0)
                count_zero++;
                else
                count_zero=0;
                sum-=nums[i];
                i++;
            }
            if(sum==goal)
            {
                count+=1+count_zero;
                
            }
            j++;
        }
        return count;
    }
};
