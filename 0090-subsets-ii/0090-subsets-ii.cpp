class Solution {
public:
vector<vector<int>>result;
void solve(vector<int>ans,vector<int>&nums,int idx)
{
    result.push_back(ans);
    for(int i=idx;i<nums.size();i++)
    {
        if(i>idx && nums[i]==nums[i-1])
        continue;
        ans.push_back(nums[i]);
        solve(ans,nums,i+1);
        ans.pop_back();
    }

}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>ans;
        
        sort(nums.begin(),nums.end());
        solve(ans,nums,0);
        return result;
    }
};