class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>vowels(words.size(),0);
        int sum=0;
        unordered_set<char>st={'a','e','i','o','u'};
        for(int i=0;i<words.size();i++)
        {
           if(st.find(words[i].front())!=st.end() && st.find(words[i].back())!=st.end())
           sum++;
           vowels[i]=sum;
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++)
        {
            int a=queries[i][0];
            int b=queries[i][1];
            if(a!=0)
            ans.push_back(vowels[b]-vowels[a-1]);
            else
             ans.push_back(vowels[b]);
        }
        return ans;
    }
};