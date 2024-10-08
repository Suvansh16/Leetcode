class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++)
        {
            if(st.empty())
            {
                st.push(s[i]);
            }
            else
            {
                if(s[i]==']' && st.top()=='[')
                st.pop();
                else
                st.push(s[i]);
            }
        }
        int a=st.size();
        int countofopen=a/2;
        return (countofopen+1)/2;
    }
};