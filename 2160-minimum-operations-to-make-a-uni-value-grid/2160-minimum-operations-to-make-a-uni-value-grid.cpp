class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> arr;

        // Flatten the grid into a 1D array
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                arr.push_back(grid[i][j]);
            }
        }

        sort(arr.begin(), arr.end());
        int mid = arr[arr.size() / 2]; // Median element
        int count = 0;

        // Compute operations
        for (int num : arr) {
            if (abs(num - mid) % x != 0) return -1; // If it's not a multiple of x
            count += abs(num - mid) / x;
        }

        return count;
    }
};
