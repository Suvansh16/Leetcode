class Solution {
public:
int temp[100001];
int solve(int start,vector<int>&nums)
{
    if(start==nums.size()-1)
    return 0;
    if(start>=nums.size())
    return INT_MAX;
    if(temp[start]!=-1)
    return temp[start];
    int steps=INT_MAX;
    int minsteps=min(nums[start]+start,(int)nums.size()-1);
    for(int i=start+1;i<=minsteps;i++)
    {
        int a=solve(i,nums);
        if(a!=INT_MAX)
        {
            steps=min(steps,1+a);
        }
    }
    temp[start]=steps;
    return temp[start];

}
    int jump(vector<int>& nums) {
        memset(temp,-1,sizeof(temp));
        return solve(0,nums);
    }
};