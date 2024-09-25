class Solution {
public:
// int dp[501][501];

// int solve(string &word1, string &word2,int i,int j)
// {
//     if(j>=word2.size())
//     {
//         return word1.size()-i;
//     }
    
//     if(i>=word1.size())//insert all element
//     return word2.size()-j;
//     if(dp[i][j]!=-1)
//     return dp[i][j];
//     if(word1[i]==word2[j])
//     {
//         return solve(word1,word2,i+1,j+1);
//     }
  
//          int insert=1+solve(word1,word2,i,j+1);
//          int  remove=1+solve(word1,word2,i+1,j);
//          int replace=1+solve(word1,word2,i+1,j+1);
//         return  dp[i][j]=min({insert,remove,replace});
   

// }
//     int minDistance(string word1, string word2) {
//         memset(dp,-1,sizeof(dp));
//         return solve(word1,word2,0,0);

//     }
     int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
         for (int i = 0; i <= m; i++) {
            dp[i][0] = i; // Deleting all characters of word1
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j; // Inserting all characters of word2
        }
         for(int i=1;i<=m;i++)
         {
            for(int j=1;j<=n;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                } 
                else
                {      
                  int insert=1+dp[i][j-1];
                  int  remove=1+dp[i-1][j];
                  int replace=1+dp[i-1][j-1];
                  dp[i][j]=min({insert,remove,replace});
                }
            }
         }
         return dp[m][n];
     }
};