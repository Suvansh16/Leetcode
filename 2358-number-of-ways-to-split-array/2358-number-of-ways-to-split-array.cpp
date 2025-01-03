class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int count=0;
       long long sum=0;
       for(int i=0;i<nums.size();i++)
       {
        sum+=nums[i];
       }
      long long  leftsum=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            sum-=nums[i];
           
            leftsum+=nums[i];
            if(leftsum>=sum)
            count++;
        }
        return count;
    }
};