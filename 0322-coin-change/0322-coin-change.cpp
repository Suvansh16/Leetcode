class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,INT_MAX));
        for(int i=0;i<coins.size();i++)
        {

            dp[i][0]=0;
        }
         for (int j = 1; j <= amount; j++) {
            if (j % coins[0] == 0) {
                dp[0][j] = j / coins[0]; // Only use the first coin repeatedly
            }
        }
        for(int i=1;i<coins.size();i++)
        {
            for(int j=1;j<=amount;j++)
            {
                int take=INT_MAX,nottake=INT_MAX;
                 nottake=dp[i-1][j];
            if(j - coins[i] >= 0 && dp[i][j-coins[i]]!=INT_MAX)
            {
            take=1+ dp[i][j-coins[i]];
            }
           dp[i][j]=min(take,nottake);
            }
        }
        return dp[coins.size()-1][amount]==INT_MAX?-1:dp[coins.size()-1][amount];
    }
};