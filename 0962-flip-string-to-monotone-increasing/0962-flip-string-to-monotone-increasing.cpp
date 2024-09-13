class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int countofones=0;
        int flip=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1')
            countofones++;
        
        else
        {
            int a=min(flip+1,countofones);
            flip=a;
        }
        }
        return flip;
    }
    
};