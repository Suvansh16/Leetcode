class Solution {
public:
    const int mod = 1e9 + 7;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (dp[i][j] != -1) return dp[i][j];
        
        int ans = 1; // Each cell itself is a path
        for (vector<int>& dir : directions) {
            int ni = i + dir[0], nj = j + dir[1];
            if (ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size() && grid[ni][nj] > grid[i][j]) {
                ans = (ans + solve(ni, nj, grid, dp)) % mod;
            }
        }
        return dp[i][j] = ans;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        int count = 0;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                count = (count + solve(i, j, grid, dp)) % mod;
            }
        }
        return count;
    }
};
