class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> diff(n + 1, 0); // Difference array

        // Populate the difference array
        for (auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2] == 1 ? 1 : -1;

            diff[start] += direction;
            if (end + 1 < n) {
                diff[end + 1] -= direction;
            }
        }

        // Calculate the prefix sum to get the net shift for each character
        vector<int> netShift(n, 0);
        int currentShift = 0;
        for (int i = 0; i < n; ++i) {
            currentShift += diff[i];
            netShift[i] = currentShift % 26; // Keep shifts within the range [0, 25]
        }

        // Apply the shifts to the string
        for (int i = 0; i < n; ++i) {
            int shift = netShift[i];
            int newChar = (s[i] - 'a' + shift + 26) % 26; // Add 26 to handle negative shifts
            s[i] = 'a' + newChar;
        }

        return s;
    }
};
