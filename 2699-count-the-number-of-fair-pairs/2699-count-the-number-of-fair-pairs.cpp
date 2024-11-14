class Solution {
public:
int maxbinary(vector<int>&nums,int num,int upper,int lower,int presentind)
{
    int l=presentind;
    int r=nums.size()-1;
     int ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(nums[mid]+num<=upper)
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }

    }
    return ans;
}
int minbinary(vector<int>&nums,int num,int upper,int lower,int presentind)
{
    int l=presentind+1;
    int r=nums.size()-1;
    int ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(nums[mid]+num>=lower)
        {
            ans=mid;
           r=mid-1;
        }
        else
        {
           l=mid+1;
        }

    }
    return ans;
}
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            int maxindex=maxbinary(nums,nums[i],upper,lower,i);
            int minindex=minbinary(nums,nums[i],upper,lower,i);
             if (maxindex >= minindex && maxindex!=0 && minindex!=0) {
                ans += (maxindex - minindex + 1);

        }
        }
        return ans;
    }
};