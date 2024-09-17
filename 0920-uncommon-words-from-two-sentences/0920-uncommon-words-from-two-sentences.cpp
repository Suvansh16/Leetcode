class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int>temp;
        vector<string>ans;
        int prev=0;
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i]==' ')
            {
                string a=s1.substr(prev,i-prev);
                temp[a]++;
                prev=i+1;
            }
        }
        if(s1[s1.length()-1]!=' ')
        temp[s1.substr(prev,s1.length()-prev+1)]++;
        prev=0;
        for(int i=0;i<s2.length();i++)
        {
            if(s2[i]==' ')
            {
                string a=s2.substr(prev,i-prev);
                temp[a]++;
                prev=i+1;
            }
        }
        if(s2[s2.length()-1]!=' ')
        temp[s2.substr(prev,s2.length()-prev+1)]++;
        for(auto i:temp)
        {
            int a=i.second;
            if(a==1)
            ans.push_back(i.first);
        }
        return ans;
    }
};