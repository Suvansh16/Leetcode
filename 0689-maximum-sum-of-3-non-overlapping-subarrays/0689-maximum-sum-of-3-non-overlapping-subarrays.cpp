class Solution {
public:
int t[20001][4];
int helper(vector<int>&sums,int i,int count,int k)
{
    if(count==0)
    return 0;
    if(i>=sums.size())
    return INT_MIN;
    if(t[i][count]!=-1)
    return t[i][count];
    int take=sums[i]+helper(sums,i+k,count-1,k);
    int nottake=helper(sums,i+1,count,k);
    return t[i][count]=max(take,nottake);
}
void solve(vector<int>&sums,int start,int count,vector<int>&indices,int k)
{
    if(count==0)
    return ;
    if(start>=sums.size())
    return ;
    int take=sums[start]+helper(sums,start+k,count-1,k);
    int nottake=helper(sums,start+1,count,k);
    if(take>=nottake)
    {
        indices.push_back(start);
        solve(sums,start+k,count-1,indices,k);

    }
    else
    {
        solve(sums,start+1,count,indices,k);
    }
}
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int>sums;
        int i=0;
        int j=0;
        int windowsum=0;
        memset(t,-1,sizeof(t));
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
        solve(sums,0,3,indices,k);
        return indices;
    }
};