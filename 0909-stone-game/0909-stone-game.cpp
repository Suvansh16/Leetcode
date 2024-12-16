class Solution {
public:
bool solve(int i,int j,int l,int alice_sum,int bob_sum,vector<int>&piles,vector<vector<vector<int>>>&dp)
{
    if(i>j)
    return alice_sum>bob_sum;
    if(dp[i][j][l]!=-1)
    return dp[i][j][l];
    bool a=false,b=false,c=false,d=false;
    if(l==0)
    {
       

        a=solve(i+1,j,1,alice_sum+piles[i],bob_sum,piles,dp);
        b=solve(i,j-1,1,alice_sum+piles[j],bob_sum,piles,dp);
    }
    if(l==1)
    {
        c=solve(i+1,j,0,alice_sum,bob_sum+piles[i],piles,dp);
       d=solve(i,j-1,0,alice_sum,bob_sum+piles[j],piles,dp);
    }
    return dp[i][j][l]=a || b || c || d ;
}
    bool stoneGame(vector<int>& piles) {
        vector<vector<vector<int>>>dp(piles.size(),vector<vector<int>>(piles.size(),vector<int>(2,-1)));
        return solve(0,piles.size()-1,0,0,0,piles,dp);
    }
};