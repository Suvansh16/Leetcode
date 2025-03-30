class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>parentmap;
        for(auto i:s)
        {
            parentmap[i]++;
        }
        int i=s.length();
        int j=0;
        vector<int>ans;
        set<char>st;
        int l=0;
        while(j<i)
        {
            st.insert(s[j]);
            parentmap[s[j]]--;
            
            if(parentmap[s[j]]==0)
            {
                st.erase(s[j]);
                if(st.empty()){
                ans.push_back(j-l+1);
                l=j+1;
                }
            }
            j++;

        }
        return ans;

    }
};