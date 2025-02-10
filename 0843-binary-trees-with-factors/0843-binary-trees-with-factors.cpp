class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        sort(arr.begin(), arr.end());
        
        unordered_map<int, long long> dp;  // Store number of trees rooted at each element
        for (int num : arr) dp[num] = 1;   // Each number alone is a valid tree
        
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0) {  // arr[j] is a factor
                    int right = arr[i] / arr[j];
                    if (dp.find(right) != dp.end()) {  // right must also exist in arr
                        dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[right]) % MOD;
                    }
                }
            }
        }
        
        long long ans = 0;
        for (auto& [key, val] : dp) ans = (ans + val) % MOD;
        return ans;
    }
};
