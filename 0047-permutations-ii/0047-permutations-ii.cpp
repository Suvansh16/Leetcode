class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums, vector<int>& output, vector<bool>& visited) {
        if (output.size() == nums.size()) {
            ans.push_back(output);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited[i]) continue;

            // Skip duplicates: only use the first unvisited duplicate in each recursion level
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) continue;

            visited[i] = true;
            output.push_back(nums[i]);
            solve(nums, output, visited);
            output.pop_back();
            visited[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // sorting helps skip duplicates
        vector<int> output;
        vector<bool> visited(nums.size(), false);
        solve(nums, output, visited);
        return ans;
    }
};
