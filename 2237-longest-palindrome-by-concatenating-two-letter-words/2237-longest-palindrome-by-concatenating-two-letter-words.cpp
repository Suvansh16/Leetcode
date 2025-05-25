class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>map;
        unordered_set<string>st;
        for(auto i:words)
        map[i]++;
        int count=0;
        bool has=false;
        for(auto &[word,freq]:map)
        {
            string t=word;
            reverse(t.begin(),t.end());
            if(word==t)
            {
                count+=(freq/2)*4;
                if(freq%2==1)
                has=true;
            }
            else
            {
                if( !st.count(word) && !st.count(t) && map.find(t)!=map.end() )
                {
                    count+=min(map[t],freq)*4;
                    st.insert(word);
                    st.insert(t);
                   
                }
            }
        }
        if(has)
        count+=2;
        return count;
    }
};