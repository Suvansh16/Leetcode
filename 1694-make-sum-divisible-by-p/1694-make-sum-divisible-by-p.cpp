class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int,int>map;
        map[0]=-1;
        int n=nums.size();
        int sum=0;
        for(int i:nums)
        {
            sum=(sum+i)%p;
        }
        if(sum==0)
        return 0;
        int target=sum%p;
        int len=n;
        int curr=0;
        for(int i=0;i<n;i++)
        {
            curr=(curr+nums[i])%p;
            if(map.find((curr-target+p)%p)!=map.end())
            {
                int a=map[(curr-target+p)%p];
                if(len>i-a)
                {
                    len=i-a;
                }

            }
           map[curr]=i;

        }
     if(len==n )
     return -1;
     return len;
    }
};