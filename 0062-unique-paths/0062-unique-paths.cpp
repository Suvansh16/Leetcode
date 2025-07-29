class Solution {
public:
vector<vector<int>>directions={{1,0},{0,1}};
int dp[101][101];
int  solve(int i,int j,int end_i,int end_j,vector<vector<bool>>&visited)
{
    if(i==end_i && j==end_j)
    {
       
        return 1;
    }
    if(dp[i][j]!=-1)
    return dp[i][j];
    int ans=0;
    visited[i][j]=true;
    for(vector<int>dir:directions)
    {
        int new_i=dir[0]+i;
        int new_j=dir[1]+j;
        if(new_i>=0 && new_i<=visited.size()-1 && new_j>=0 && new_j<=visited[0].size()-1 && visited[new_i][new_j]==false)
        {
            if(solve(new_i,new_j,end_i,end_j,visited))
            ans+=solve(new_i,new_j,end_i,end_j,visited);
        }
    }

     visited[i][j]=false;
     return dp[i][j]=ans;

}
    int uniquePaths(int m, int n) {
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        memset(dp,-1,sizeof(dp));
         return solve(0,0,m-1,n-1,visited);
       

    }
};