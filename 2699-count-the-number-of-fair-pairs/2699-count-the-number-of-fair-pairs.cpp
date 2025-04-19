class Solution {
public:
int findmaxindex(int num,vector<int>&nums,int upper,int presentind)
{
    int n=nums.size();
    int i=presentind;
    int j=n-1;
    int ans=-1;
    while(i<=j)
    {
        int mid=(i+j)/2;
        if(nums[mid]+num<=upper){
        ans=mid;
        i=mid+1;
        }
        else
        j=mid-1;

    }
    return ans;
}
int findminindex(int num,vector<int>&nums,int lower,int presentind)
{
    int i=presentind;
    int j=nums.size()-1;
    int ans=-1;
    while(i<=j)
    {
        int mid=(i+j)/2;
        if(nums[mid]+num>=lower)
        {
            ans=mid;
            j=mid-1;
        }
        else
        i=mid+1;
    }
    return ans;
}
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long count=0;
        for(int i=0;i<nums.size();i++)
        {
            int maxindex=findmaxindex(nums[i],nums,upper,i+1);
            int minindex=findminindex(nums[i],nums,lower,i+1);
            if(minindex!=-1 && maxindex!=-1 && maxindex>=minindex)
            count+=(maxindex-minindex+1);
        }
        return count;
    }
};