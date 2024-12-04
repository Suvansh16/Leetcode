class Solution {
public:
int solve(vector<vector<int>>& piles,int row, int k,vector<vector<int>>&dp)
{
    if(k==0 || row>=piles.size())
    return 0;
    if(dp[row][k]!=-1)
    return dp[row][k];
   int nottake=solve(piles,row+1,k,dp);
   int take=0;
   int currsum=0;
   for(int i=0;i<min(k,(int)piles[row].size());i++)
   {
    currsum+=piles[row][i];
    take=max(take,currsum+solve(piles,row+1,k-i-1,dp));
   }
   return dp[row][k]=max(take,nottake);

}
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>>dp(piles.size(),vector<int>(2001,-1));
        return solve(piles,0,k,dp);
    }
};