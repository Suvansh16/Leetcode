class Solution {
public:
int n;
int dp[101][101][2];
int solve(int start,vector<int>&piles,int m,int turn)
{
    if(start>=piles.size())
    return 0;
    if(dp[start][m][turn]!=-1)
    return dp[start][m][turn];
    int result=(turn==1)?-1:INT_MAX;
    int stones=0;

    for(int i=1;i<=min(2*m,n-start);i++)
    {
        stones+=piles[start+i-1];
        if(turn==1)
        {
            result=max(result,stones+solve(i+start,piles,max(m,i),0));

        }
        else
        {
            result=min(result,solve(i+start,piles,max(m,i),1));
        }
    }
    return dp[start][m][turn]=result;
}
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,piles,1,1);
    }
};