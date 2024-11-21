class Solution {
public:
    int takeCharacters(string s, int k) {
        int total_a = 0, total_b = 0, total_c = 0;
        int n = s.length();
        
        // Count total occurrences of 'a', 'b', and 'c'
        for (char c : s) {
            if (c == 'a') total_a++;
            else if (c == 'b') total_b++;
            else if (c == 'c') total_c++;
        }
        
        // If any character count is less than k, it's impossible to satisfy
        if (total_a < k || total_b < k || total_c < k) return -1;
        
        // Sliding window to find the longest subarray satisfying constraints
        int count_a = 0, count_b = 0, count_c = 0;
        int i = 0, max_window_size = 0;

        for (int j = 0; j < n; j++) {
            if (s[j] == 'a') count_a++;
            else if (s[j] == 'b') count_b++;
            else if (s[j] == 'c') count_c++;

            // Shrink the window if constraints are violated
            while (total_a - count_a < k || total_b - count_b < k || total_c - count_c < k) {
                if (s[i] == 'a') count_a--;
                else if (s[i] == 'b') count_b--;
                else if (s[i] == 'c') count_c--;
                i++;
            }

            // Update the maximum window size
            max_window_size = max(max_window_size, j - i + 1);
        }

        // Minimum characters to remove = total length - largest valid window
        return n - max_window_size;
    }
};
