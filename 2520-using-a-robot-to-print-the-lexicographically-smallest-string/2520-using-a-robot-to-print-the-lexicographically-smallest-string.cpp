class Solution {
public:
    string robotWithString(string s) {
        vector<int> freq(26, 0);
        for (char ch : s) freq[ch - 'a']++;

        string ans, stack;
        char mini = 'a';

        for (char ch : s) {
            freq[ch - 'a']--;
            stack.push_back(ch);

            // Update mini to next smallest available char
            while (mini <= 'z' && freq[mini - 'a'] == 0)
                mini++;

            // Pop from stack while top is <= current mini
            while (!stack.empty() && stack.back() <= mini) {
                ans.push_back(stack.back());
                stack.pop_back();
            }
        }

        return ans;
    }
};
