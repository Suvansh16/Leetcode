class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;

        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        if (mini == maxi) return 0;

        int bucketSize = ceil((maxi - mini) * 1.0 / (nums.size() - 1));
        int bucketCount = nums.size() - 1;

        vector<int> min_arr(bucketCount, INT_MAX);
        vector<int> max_arr(bucketCount, INT_MIN);

        for (int num : nums) {
            if (num == mini || num == maxi) continue;
            int idx = (num - mini) / bucketSize;
            min_arr[idx] = min(min_arr[idx], num);
            max_arr[idx] = max(max_arr[idx], num);
        }

        int prev = mini;
        int res = 0;

        for (int i = 0; i < bucketCount; i++) {
            if (min_arr[i] == INT_MAX && max_arr[i] == INT_MIN) continue; // empty bucket
            res = max(res, min_arr[i] - prev);
            prev = max_arr[i];
        }

        res = max(res, maxi - prev);
        return res;
    }
};
