class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int j=nums.size()-1;
        int i=j-1;
        bool flag=false;
        map<int,int>map;
        int a;
        while(j>0)
        {
            if(!map[nums[j]])
            {
                map[nums[j]]=j;
            }
            if(nums[j]>nums[i] && flag==false)
            {
                for(auto m:map)
                {
                    if(m.first>nums[i])
                    {
                        swap(nums[i],nums[m.second]);
                        a=i;
                        break;
                    }
                }
                flag=true;
            }
            j--;
            i--;
        }
        if(flag==true)
        reverse(nums.begin()+a+1,nums.end());
        if(flag==false)
        sort(nums.begin(),nums.end());
    }
};
