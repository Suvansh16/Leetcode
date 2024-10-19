class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) return '0';  // Base case
        
        int length = (1 << n) - 1;  // Length of the current string
        int mid = length / 2 + 1;   // The middle index (1-based)

        if (k == mid) {
            return '1';  // Middle element is always '1'
        } else if (k < mid) {
            return findKthBit(n - 1, k);  // First half, similar to the previous string
        } else {
            // Second half, invert the mirrored bit from the first half
            char ch = findKthBit(n - 1, length - k + 1);
            return ch == '0' ? '1' : '0';
        }
    }
};
