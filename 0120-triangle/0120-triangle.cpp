class Solution {
public:
int solve(int i,int j,vector<vector<int>>&triangle, vector<vector<int>>&dp){
if(i>=triangle.size())
return 0;
if(dp[i][j]!=-1)
return dp[i][j];
int taken_i=INT_MAX;
int taken_ii=INT_MAX;
taken_i=triangle[i][j]+solve(i+1,j,triangle,dp);
taken_ii=triangle[i][j]+solve(i+1,j+1,triangle,dp);
return dp[i][j]=min(taken_i,taken_ii);
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int t=triangle[n-1].size();
        vector<vector<int>>dp(triangle.size(),vector<int>(t,-1));
        return solve(0,0,triangle,dp);
    }
};