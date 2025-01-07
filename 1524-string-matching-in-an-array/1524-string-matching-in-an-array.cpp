class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        for (int i = 0; i < n; i++) {
            string a = words[i];
            for (int j = 0; j < n; j++) {
                if (i != j && words[j].find(a) != string::npos) {
                    ans.push_back(a);
                    break; // Stop searching once you find `a` in `words[j]`.
                }
            }
        }
        return ans;
    }
};
