class FindSumPairs {
public:
    unordered_map<int, int> freqNums1;
    unordered_map<int, int> freqNums2;
    vector<int> nums2;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2Input) {
        for (int num : nums1)
            freqNums1[num]++;
        nums2 = nums2Input;
        for (int num : nums2)
            freqNums2[num]++;
    }

    void add(int index, int val) {
        int oldVal = nums2[index];
        freqNums2[oldVal]--;
        if (freqNums2[oldVal] == 0)
            freqNums2.erase(oldVal);
        nums2[index] += val;
        freqNums2[nums2[index]]++;
    }

    int count(int tot) {
        int ans = 0;
        for (const auto& [num2, freq2] : freqNums2) {
            int complement = tot - num2;
            if (freqNums1.count(complement)) {
                ans += freq2 * freqNums1[complement];
            }
        }
        return ans;
    }
};
