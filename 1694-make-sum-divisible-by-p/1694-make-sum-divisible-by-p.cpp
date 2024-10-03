class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
    
       map<int,int> mp;
       mp[0]=-1;
       int prefix_sum_R=0;
       int ans=nums.size();
       int total_sum=0;
       for(auto val: nums)
       {
           total_sum = (total_sum+val)%p;


       }
       if(total_sum==0)
       {
           return 0;
       }
       for(int i=0;i<nums.size();i++)
       {
           prefix_sum_R=(prefix_sum_R+nums[i])%p;
           int check =(prefix_sum_R-total_sum+p)%p;
           if(mp.find(check)!=mp.end())
           {
                ans=min(ans,i-mp[check]);
           }
       
             mp[prefix_sum_R]=i;
        }
        if(ans==nums.size())
            return -1;
        else
             return ans;
    }
       
}; 
        
        
        

        