class Solution {
public:
int solve(int i,int j,string word1 ,string word2,vector<vector<int>>&dp){
if(word1==word2)
return 0;
else if(i==word1.size() )
return word2.size()-j;
else if(j==word2.size() )
return word1.size()-i;
if(dp[i][j]!=-1)
return dp[i][j];
if(word1[i]==word2[j])
return dp[i][j]=solve(i+1,j+1,word1,word2,dp);

int replace=INT_MAX,todelete=INT_MAX,toinsert=INT_MAX;
 if(word1[i]!=word2[j])
{
    replace=solve(i+1,j+1,word1,word2,dp);
    todelete=solve(i+1,j,word1,word2,dp);
    toinsert=solve(i,j+1,word1,word2,dp);
   
}
  return dp[i][j]=min({replace,todelete,toinsert})+1;
}
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size() ,vector<int>(word2.size(),-1));
        return solve(0,0,word1,word2,dp);
    }
};