class Solution {
public:
vector<vector<int>>ans;
void solve(int start,vector<int>&nums,int target,vector<int>output)
{
    if(target==0)
    {
        ans.push_back(output);
        return ;
    }
    if(start>=nums.size() ||  target<0)
    return ;
    for(int i=0;i<nums.size();i++)
    {
        output.push_back(nums[i]);
        solve(i,nums,target-nums[i],output);
        output.pop_back();
    }


}
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>output;
        sort(nums.begin(),nums.end());
        solve(0,nums,target,output);
        return ans.size();
    }
};