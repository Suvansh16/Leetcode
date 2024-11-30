class Solution {
public:
int m,n;
int solve(int start1,int start2,string &text1,string &text2,vector<vector<int>>&dp)
{
    if(start1>=m || start2>=n)
    {
         return 0;
    }
    if(dp[start1][start2]!=-1)
    return dp[start1][start2];
    if(text1[start1]==text2[start2])
    {
       
         dp[start1][start2]=1+solve(start1+1,start2+1,text1,text2,dp);
    }
   else
   {
      dp[start1][start2]=max(solve(start1+1,start2,text1,text2,dp) ,solve(start1,start2+1,text1,text2,dp));
   }
   return dp[start1][start2];

}

    int longestCommonSubsequence(string text1, string text2) {
       vector<vector<int>>dp(1001,vector<int>(1001,-1));
       m=text1.size();
       n=text2.size();
    return  solve(0,0,text1,text2,dp);
     
        
    }
};