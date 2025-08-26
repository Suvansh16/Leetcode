class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());

        unordered_map<int,int> freq;
        for(int num : nums) freq[num]++;

        vector<int> points(maxi+1, 0);
        for(auto &p : freq) {
            points[p.first] = p.first * p.second;
        }

        vector<int> dp(maxi+1, 0);
        dp[0] = 0;
        dp[1] = points[1];

        for(int i = 2; i <= maxi; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + points[i]);
        }

        return dp[maxi];
    }
};
