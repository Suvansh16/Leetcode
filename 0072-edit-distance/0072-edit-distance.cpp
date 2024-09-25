class Solution {
public:
int dp[501][501];
int solve(string &word1, string &word2,int i,int j)
{
    if(j>=word2.size())
    {
        return word1.size()-i;
    }
    
    if(i>=word1.size())//insert all element
    return word2.size()-j;
    if(dp[i][j]!=-1)
    return dp[i][j];
    if(word1[i]==word2[j])
    {
        return solve(word1,word2,i+1,j+1);
    }
  
         int insert=1+solve(word1,word2,i,j+1);
         int  remove=1+solve(word1,word2,i+1,j);
         int replace=1+solve(word1,word2,i+1,j+1);
        return  dp[i][j]=min({insert,remove,replace});
   

}
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return solve(word1,word2,0,0);

    }
};