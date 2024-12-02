class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool>ans(nums.size(),false);
        ans[0]=true;
        for(int i=1;i<=nums.size()-1;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(ans[j]==true && nums[j]+j>=i)
                {
                    ans[i]=true;
                    break;
                }
            }
        }
        return ans[nums.size()-1];
    }
};