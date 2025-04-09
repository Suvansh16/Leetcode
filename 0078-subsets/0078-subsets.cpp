class Solution {
public:
vector<vector<int>>ans;
void solve(int start,vector<int>&nums,vector<int>output)
{
    if(start>=nums.size())
    {
        ans.push_back(output);
        return ;
    }

        
        output.push_back(nums[start]);
        solve(start+1,nums,output);
        output.pop_back();
        
        solve(start+1,nums,output);


}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>output;
        // sort(nums.begin(),nums.end());
        solve(0,nums,output);
        return ans;
    }
};