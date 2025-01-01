class Solution {
public:
    int maxScore(string s) {
        int ones=0;
        int zeroes=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='0')
            zeroes++;
            else
            ones++;
        }
       
        int maxans=0,z=0;
        for(int i=0;i<s.length()-1;i++)
        {
            if(s[i]=='0')
            z++;
            if(s[i]=='1')
            ones--;
            maxans=max(maxans,z+ones);
        }
        
        return maxans;
    }
};