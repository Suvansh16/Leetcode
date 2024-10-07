class Solution {
public:
    int minLength(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++)
        {
            if(st.empty())
            st.push(s[i]);
            else
            {
                char c=s[i];
                char t=st.top();
                string l;
                l.push_back(t);
                l.push_back(c);
                if(l=="AB" || l=="CD")
                {
                    st.pop();
                }
                else
                {
                    st.push(c);
                }
            }
        }
        return st.size();
    }
};