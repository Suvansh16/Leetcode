class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1]){
            nums[i]*=2;
            nums[i+1]=0;
            }
        }
         for(int i=0;i<nums.size();i++)
        {
           cout<<nums[i]<<endl;
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]!=0)
            continue;
            else
            {
                int t=i;
                while(t<nums.size()-1 && nums[t+1]!=0)
                {
                    swap(nums[t],nums[t+1]);
                    t++;
                }
            }
        }
        return nums;
    }
};