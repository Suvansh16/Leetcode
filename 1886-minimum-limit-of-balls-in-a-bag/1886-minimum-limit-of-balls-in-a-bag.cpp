class Solution {
public:
bool possible(int mid,int maxopr,vector<int>&nums)
{
    int opr=0;
    for(int i=0;i<nums.size();i++)
    {
        int o=nums[i]/mid;
        opr+=o;
        if(nums[i]%mid==0)
            opr-=1;

    
    }
    if(opr<=maxopr)
    return true;
    return false;
}
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l=1;
        int r=*max_element(nums.begin(),nums.end());
        int result=r;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(possible(mid,maxOperations,nums))
            {
                result=mid;
                r=mid-1;
            }
            else
            l=mid+1;

        }
        return result;
    }
};