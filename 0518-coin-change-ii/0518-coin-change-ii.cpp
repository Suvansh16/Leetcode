class Solution {
public:
  
    int solve(int index, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (amount == 0) return 1;
        if (index >= coins.size() || amount < 0) return 0;

        if (dp[index][amount] != -1) return dp[index][amount];

        // Not take the current coin
        int notTake = solve(index + 1, amount, coins, dp);

        // Take the current coini
        int take=solve(index,amount-coins[index],coins,dp);
        return dp[index][amount] = take+notTake;
    }
    int change(int amount, vector<int>& coins) {
       int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int result = solve(0, amount, coins, dp);
        return result == INT_MAX ? 0: result;

  
    }
};