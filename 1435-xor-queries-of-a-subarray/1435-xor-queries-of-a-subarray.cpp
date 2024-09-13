class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int>prefix(n);
        vector<int>ans;
        prefix[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]^arr[i];
        }
        for(int i=0;i<queries.size();i++)
        {
            int a=queries[i][0];
            int b=queries[i][1];
            if(a==0)
            {
                ans.push_back(prefix[b]);
            }
            else
            {
                ans.push_back(prefix[b]^prefix[a-1]);
            }
        }
        return ans;
    }
};