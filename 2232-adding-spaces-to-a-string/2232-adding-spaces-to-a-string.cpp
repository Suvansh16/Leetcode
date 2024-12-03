class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        int l=0;
        for(int i=0;i<spaces.size();i++)
        {
            int a=spaces[i];
            while(l!=a)
            {
                ans.push_back(s[l]);
                l++;
            }
            ans+=" ";

        }
        while(l!=s.length()){
        ans.push_back(s[l]);
        l++;
        }
        return ans;
    }
};