class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
          sort(satisfaction.begin(),satisfaction.end());
        vector<vector<long long>>dp(501,vector<long long>(501,INT_MIN));
        for(int i=0;i<501;i++)
        {
            dp[i][0]=0;
        }
        dp[0][1]=satisfaction[0];
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                long long cost1=satisfaction[i]*j+dp[i-1][j-1];
                long long cost2=dp[i-1][j];
                dp[i][j]=max(cost1,cost2);
            }
        }
         long long  maxans=0;
        for(int i=0;i<=n;i++)
        {
            maxans=max(maxans,dp[n-1][i]);
        }
        return maxans;
       
    }
};