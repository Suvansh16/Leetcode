class Solution {
public:
    int countPrefix(long prefix, int n) {
        long curr = prefix, next = prefix + 1;
        long count = 0;
        while (curr <= n) {
            count += min((long)n + 1, next) - curr;
            curr *= 10;
            next *= 10;
        }
        return count;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;
        k--; // because we start from 1 already

        while (k > 0) {
            int count = countPrefix(curr, n);
            if (count <= k) {
                // Skip this whole subtree
                k -= count;
                curr += 1;
            } else {
                // Go deeper in the tree
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }
};
