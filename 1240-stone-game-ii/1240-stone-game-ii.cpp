class Solution {
public:
int n;
int t[101][2][101];
int solve(int idx,int turn,int m,vector<int>&piles)
{
    if(idx>=n)
    return 0;
    if(t[idx][turn][m]!=-1)
    return t[idx][turn][m];

    int result=(turn==1?-1:INT_MAX);
    int stones=0;
    for(int i=1;i<=min(2*m,n-idx);i++)
    {
        stones+=piles[idx+i-1];
        if(turn==1)
        {
            result=max(result,stones+solve(i+idx,0,max(m,i),piles));
        }
        else
        {
            result=min(result,solve(i+idx,1,max(m,i),piles));
        }
    }
    return t[idx][turn][m]=result;
}
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        memset(t,-1,sizeof(t));
        return solve(0,1,1,piles);
    }
};