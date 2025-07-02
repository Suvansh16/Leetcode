class Solution {
public:
void solve(vector<vector<int>>&ans,vector<int>&candidates,int target,int start,vector<int>output)
{
    if(target==0){
    ans.push_back(output);
    return ;
    }
    if(target<0 || start>=candidates.size())
    return ;
    for(int i=start;i<candidates.size();i++)
    {
        if(i>start && candidates[i]==candidates[i-1])
        continue;
        output.push_back(candidates[i]);
        solve(ans,candidates,target-candidates[i],i+1,output);
        output.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        vector<int>output;
        solve(ans,candidates,target,0,output);
        return ans;
    }
};