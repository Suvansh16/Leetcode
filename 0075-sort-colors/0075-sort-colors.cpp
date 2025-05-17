class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a=0;
        int b=0;
        int c=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                a++;
            }
            else if(nums[i]==1)
            {
                b++;
            }
            else
            c++;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(a)
            {
                 nums[i]=0;
                 a--;
            }
           
            else if(b)
            {
                nums[i]=1;
                b--;
            }
            
            else
            nums[i]=2;
        }

    }
};