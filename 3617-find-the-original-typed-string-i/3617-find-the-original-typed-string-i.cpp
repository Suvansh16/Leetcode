class Solution {
public:
    int possibleStringCount(string word) {
        int count=0;
        char  prev='1';
        int t=0;
        for(char ch:word)
        {
            if(ch==prev)
            {
                t++;
            }
            else
            {
                count+=t;
                t=0;
                prev=ch;
            }
        }
        if(t!=0)
        count+=t;
        return count+1;
    }
};