class Solution {
public:
    int maxDifference(string s) {
        vector<int>t(26,0);
        for(char ch:s)
        t[ch-'a']++;
        int maxodd=0;
        int maxeven=INT_MAX;
        for(int i:t)
        {
            if(i%2!=0)
            maxodd=max(maxodd,i);
            else
            maxeven=max(maxeven,i);
        }
        if(maxodd>=maxeven)
        return maxodd-maxeven;
          for(int i:t)
        {
            if(i%2!=0)
            maxodd=max(maxodd,i);
            else if(i!=0 && i%2==0)
            maxeven=min(maxeven,i);
        }
         return maxodd-maxeven;
    }
};