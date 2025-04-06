class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int t=triangle[n-1].size();
        vector<vector<int>>dp(n,vector<int>(t,INT_MAX));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<t;j++)
            {
                if(j<triangle[i].size())
                dp[i][j]=triangle[i][j];
            }
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                if(j-1>=0)
                dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])+dp[i][j];
                else
                dp[i][j]=dp[i][j]+dp[i-1][j];
            }
        }
        int mini=INT_MAX;
        for(int j=0;j<t;j++)
        {
            mini=min(dp[n-1][j],mini);
        }
        return mini;
    }
};