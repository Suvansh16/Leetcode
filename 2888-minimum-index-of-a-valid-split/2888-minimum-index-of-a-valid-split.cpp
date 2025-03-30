class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int>map;
        for(int &i:nums)
        {
            map[i]++;
        }
        int n=nums.size();
        int dom=-1;
        int count=-1;
        for(auto [num,freq]:map)
        {
            if(freq>(n/2))
            {
                dom=num;
                count=freq;
                break;
            }
        }
        int leftcount=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==dom)
           leftcount++;
           int leftsize=i+1;
           int rightsize=n-i-1;
           int rightcount=count-leftcount;
           if(leftcount>(leftsize/2) && rightcount>(rightsize/2))
           return i;
        }
        return -1;

    }
};