class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        int n=q.size();
        vector<long long>dp(200001,0);
        for(int i=n-1;i>=0;i--)
        {
            dp[i]=max(dp[i+1],q[i][0]+dp[i+q[i][1]+1]);

        }
        return dp[0];
    }
};