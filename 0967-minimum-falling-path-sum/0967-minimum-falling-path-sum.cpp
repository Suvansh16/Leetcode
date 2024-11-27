class Solution {
public:
int m,n;
    int minFallingPathSum(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int ans1=INT_MAX,ans2=INT_MAX,ans3=INT_MAX;
                if(j-1>=0)
                {
                    ans1=dp[i-1][j-1];
                }
                ans2=dp[i-1][j];
                if(j+1<n)
                ans3=dp[i-1][j+1];
                dp[i][j]=min({ans1,ans2,ans3})+matrix[i][j];
            }
        }
        int final=INT_MAX;
        for(int i=0;i<n;i++)
        {
            final=min(dp[m-1][i],final);
        }
        return final;
    }
};