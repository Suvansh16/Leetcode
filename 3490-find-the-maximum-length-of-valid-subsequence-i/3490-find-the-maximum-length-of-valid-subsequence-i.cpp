class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even=0,odd=0;
        for(int i:nums)
        {
            if(i%2==0)
            even++;
            else
            odd++;

        }
        int random1=0,random2=0;
        int flag=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0 && flag==0)
            {random1++;
            flag=1;
            }
            else if(nums[i]%2!=0 && flag==1)
            {
                random1++;
                flag=0;
            }
        }
        flag=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2!=0 && flag==0)
            {random2++;
            flag=1;
            }
            else if(nums[i]%2==0 && flag==1)
            {
                random2++;
                flag=0;
            }
        }
        return max({even,odd,random1,random2});
    }
};