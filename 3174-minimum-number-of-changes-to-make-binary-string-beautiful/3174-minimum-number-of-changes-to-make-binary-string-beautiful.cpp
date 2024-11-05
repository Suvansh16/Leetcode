class Solution {
public:
    int minChanges(string s) {
        int a=s.length();
        char prev=s[0];
        int count=0;
        for(int i=1;i<a;i++)
        {
            if((i+1)%2!=0)
            prev=s[i];
            else if(prev!=s[i])
            count++;
        }
        return count;
    }
};