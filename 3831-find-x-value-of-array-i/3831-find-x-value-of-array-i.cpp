class Solution {
public:
long long solve(int start,int k,vector<int>&nums,int x,int mul,vector<vector<long long>>&dp)
{
    if(start>=nums.size())
    return 0;
    if(dp[start][mul+1]!=-1)
    return dp[start][mul+1];
    long long op1=0;
    long long op2=0;
    long long count=0;
    if(mul==-1)
    {
        if(nums[start]==x)
        count++;
        op1=count+solve(start+1,k,nums,x,nums[start],dp);
        op2=solve(start+1,k,nums,x,-1,dp);
    }
    else
    {
        if((mul*nums[start])%k==x)
        count++;
        op1=count+solve(start+1,k,nums,x,(mul*nums[start])%k,dp);
    }
    return dp[start][mul+1]=op1+op2;
}
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long>result;
        for(int i=0;i<nums.size();i++)
        nums[i]=nums[i]%k;
        vector<vector<long long>>dp;
        int n=nums.size();

        for(int x=0;x<k;x++)
        {
            dp.assign(n,vector<long long>(k+1,-1));
            result.push_back(solve(0,k,nums,x,-1,dp));
        }
        return result;
    }
};