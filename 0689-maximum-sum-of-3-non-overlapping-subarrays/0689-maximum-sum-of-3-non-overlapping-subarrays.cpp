class Solution {
public:
int t[20001][4];
int helper(vector<int>&sums,int k,int idx,int rem)
{
    if(rem==0)
    return 0;
    if(idx>=sums.size())
    return INT_MIN;
    if(t[idx][rem]!=-1)
    return t[idx][rem];
    int take=sums[idx]+helper(sums,k,idx+k,rem-1);
    int nottake=helper(sums,k,idx+1,rem);
    t[idx][rem]=max(take,nottake);
    return t[idx][rem];
}
void solve(vector<int>&sums,int k,int idx,int rem,vector<int>&indices)
{
    if(rem==0)
    return ;
    if(idx>=sums.size())
    return ;
    int take=sums[idx]+helper(sums,k,idx+k,rem-1);
    int nottake=helper(sums,k,idx+1,rem);
    if(take>=nottake)
    {
        indices.push_back(idx);
        solve(sums,k,idx+k,rem-1,indices);
    }
    else
    {
        solve(sums,k,idx+1,rem,indices);
    }
    
}
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        memset(t,-1,sizeof(t));
        int i=0;
        int j=0;
        int windowsum=0;
        vector<int>sums;
        while(j<nums.size())
        {
            windowsum+=nums[j];
            if(j-i+1==k)
            {
                sums.push_back(windowsum);
                windowsum-=nums[i];
                i++;
            }
            j++;
        }
        vector<int>indices;
        solve(sums,k,0,3,indices);
        return indices;

    }
};