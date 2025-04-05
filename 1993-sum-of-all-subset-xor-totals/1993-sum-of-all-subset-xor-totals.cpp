class Solution {
public:
int solve(int start,vector<int>&nums,int xors)
{
    if(start>=nums.size())
    return xors;
    int x=solve(start+1,nums,xors);
    int y=solve(start+1,nums,xors^nums[start]);
    return x+y;
}
    int subsetXORSum(vector<int>& nums) {
        int xors=0;
        return solve(0,nums,xors);
    }
};