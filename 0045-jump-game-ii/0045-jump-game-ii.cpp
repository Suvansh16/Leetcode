class Solution {
public:
    int solve(int start, vector<int>& nums, vector<int>& dp) {
        if (start >= nums.size() - 1) return 0;
        if (dp[start] != -1) return dp[start];

        int ans = INT_MAX;
        for (int i = start + 1; i <= min((int)nums.size() - 1, start + nums[start]); i++) {
            int t = solve(i, nums, dp);
            if (t != INT_MAX)
                ans = min(ans, t + 1);
        }
        return dp[start] = ans;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(0, nums, dp);
    }
};
