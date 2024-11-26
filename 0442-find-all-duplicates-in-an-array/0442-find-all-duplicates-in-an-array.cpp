class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
     vector<int>ans;
     for(int i=0;i<nums.size();i++)
     {
        int a=abs(nums[i]);
        int l=a-1;
        if(nums[l]<0)
        {
            ans.push_back(abs(nums[i]));

        }
        else
        {
            nums[l]=-1*nums[l];
        }
     } 
      return ans;  
    }
   
};