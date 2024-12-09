class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool>ans;
        vector<int>validindex;
        int i=0;int j=0;
        int n=nums.size();
        while(i<n)
        {
            if(j<i)
            {
                j=i;
            }
            while(j+1<n && nums[j]%2 !=nums[j+1]%2)
            {
                j++;
            }
            validindex.push_back(j);
            i++;
        }
        for(int i=0;i<queries.size();i++)
        {
            int a=queries[i][0];
            int b=queries[i][1];
            if(validindex[a]>=b)
            ans.push_back(true);
            else
            ans.push_back(false);

        }
        return ans;

    }
};