class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>v;
        vector<bool>ans;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
          if(i==0)
          v.push_back(sum);
          else
          {
            bool a=(nums[i]%2==0);
            bool b=(nums[i-1]%2==0);
            if(a==b)
            {
                sum+=1;
                v.push_back(sum);
            }
            else
            v.push_back(sum);
          }
        }
        for(int i=0;i<queries.size();i++)
        {
            int a=queries[i][0];
            int b=queries[i][1];
            if(v[b]-v[a]==0)
            {
                ans.push_back(true);
            }
            else
            ans.push_back(false);
        }
        return ans;

    }
};