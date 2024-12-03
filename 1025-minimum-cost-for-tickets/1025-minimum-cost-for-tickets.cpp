class Solution {
public:
    int solve(int start, vector<int>& days, vector<int>& costs, vector<int>& dp) {
        // Base case: if we've processed all days
        if (start >= days.size()) 
            return 0;
        
        // If we've already computed the result for this subproblem, return it
        if (dp[start] != -1) 
            return dp[start];
        
        // Option 1: Buy a 1-day pass
        int cost1 = costs[0] + solve(start + 1, days, costs, dp);
        
        // Option 2: Buy a 7-day pass
        int i = start;
        while (i < days.size() && days[i] < days[start] + 7) {
            i++;
        }
        int cost2 = costs[1] + solve(i, days, costs, dp);
        
        // Option 3: Buy a 30-day pass
        int j = start;
        while (j < days.size() && days[j] < days[start] + 30) {
            j++;
        }
        int cost3 = costs[2] + solve(j, days, costs, dp);
        
        // Store the minimum cost for the current start day
        return dp[start] = min({cost1, cost2, cost3});
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), -1);  // Initialize dp array with -1
        return solve(0, days, costs, dp); // Start from the first day
    }
};
