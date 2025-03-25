class Solution {
public:
    unordered_map<int, unordered_set<int>> dp;

    bool solve(int i, int walk, vector<int>& stones, unordered_map<int, int>& index) {
        if (i == stones.size() - 1) return true;
        if (dp[i].count(walk)) return false; // Memoization: avoid recomputation
        dp[i].insert(walk);

        for (int jump : {walk - 1, walk, walk + 1}) {
            if (jump > 0 && index.count(stones[i] + jump)) {
                if (solve(index[stones[i] + jump], jump, stones, index)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool canCross(vector<int>& stones) {
        if (stones[1] != 1) return false; // First jump must be 1
        unordered_map<int, int> index;  // Maps stone value to index
        for (int i = 0; i < stones.size(); i++) {
            index[stones[i]] = i;
        }
        return solve(0, 0, stones, index);
    }
};
