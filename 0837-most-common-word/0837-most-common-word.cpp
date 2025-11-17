class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {

        unordered_set<string> bannedSet;
        for (string s : banned) {
            for (char &c : s) c = tolower(c);
            bannedSet.insert(s);
        }

        unordered_map<string,int> freq;
        string word = "";

        for (int i = 0; i <= paragraph.size(); i++) {

            if (i < paragraph.size() && isalpha(paragraph[i])) {
                word.push_back(tolower(paragraph[i]));
            } 
            else {
                if (!word.empty()) {
                    if (bannedSet.count(word) == 0)
                        freq[word]++;

                    word = ""; // reset
                }
            }
        }

        // find max occurring word
        int best = 0;
        string ans = "";
        for (auto &p : freq) {
            if (p.second > best) {
                best = p.second;
                ans = p.first;
            }
        }

        return ans;
    }
};
