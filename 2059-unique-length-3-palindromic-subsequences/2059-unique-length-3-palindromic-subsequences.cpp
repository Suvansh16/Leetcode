class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char>char_set;
        for(char ch:s)
        {
            char_set.insert(ch);
        }
        int result=0;
        for(auto ch:char_set)
        {
            int firstindex=-1;
            int lastindex=-1;
            for(int i=0;i<s.length();i++)
            {
                if(s[i]==ch){
                if(firstindex==-1)
                firstindex=i;
                lastindex=i;
                }
            }
            unordered_set<char>uniq;
            for(int i=firstindex+1;i<lastindex;i++)
            {
                uniq.insert(s[i]);
            }
            result+=uniq.size();
        }
        return result;
    }
};