class Solution {
public:

int  solve(int idx,int curror,int maxor,vector<int>&nums)
{
    if(idx==nums.size())
    {
        if(curror==maxor)
        return 1;
        return 0;
    }
    int take=solve(idx+1,curror|nums[idx],maxor,nums);
    int nottake=solve(idx+1,curror,maxor,nums);
    return take+nottake;
}
    int countMaxOrSubsets(vector<int>& nums) {
      int maxor=0;
      for(int i=0;i<nums.size();i++)
      {
        maxor=maxor|nums[i];
      }
      int n=nums.size();
      int curror=0;

      return solve(0,0,maxor,nums);

    }
};