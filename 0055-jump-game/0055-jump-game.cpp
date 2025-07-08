class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size(), false);
        dp[nums.size() - 1] = true; // Can always reach end from the end

        for (int i = nums.size() - 2; i >= 0; i--) {
            int farthest = min((int)nums.size() - 1, i + nums[i]);
            for (int j = i + 1; j <= farthest; j++) {
                if (dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
