class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int m=v.size(),n=v[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        bool z=false;
        for (int i=0;i<m;i++){
            if (v[i][0]==1){
                z=true;
            }
            if (!z)   dp[i][0]=1;
            else dp[i][0]=0;
        }
         z=false;
        for (int i=0;i<n;i++){
             if (v[0][i]==1){
                z=true;
            }
            if (!z)   dp[0][i]=1;
            else dp[0][i]=0;
        }
        for (int i =1;i<m;i++){
            for (int j=1;j<n;j++){
                if (v[i][j]==1) {
                    dp[i][j]=0;
                }
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
        

    }
};