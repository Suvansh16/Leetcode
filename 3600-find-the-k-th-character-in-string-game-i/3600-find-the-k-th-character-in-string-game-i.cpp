class Solution {
public:
    char kthCharacter(int k) {
        string t="a";
        while(t.length()<k)
        {
            string m;
            for(char ch:t)
            {
                int a=ch-'a';
                int b=a+1;
                b=b%26;
                char l=b+'a';
                m.push_back(l);
            }
            t=t+m;
        }
        return t[k-1];
    }
};