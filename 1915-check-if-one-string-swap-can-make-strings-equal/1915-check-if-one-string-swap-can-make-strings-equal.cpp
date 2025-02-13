class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.length();
        int count=0;
        char a,b,c,d;
        bool m=false;
        for(int i=0;i<n;i++)
        {
            if(s1[i]!=s2[i]){
            count++;
             if(count>2)
             return false;
            if(m==false)
            {
                a=s1[i];
                b=s2[i];
                m=true;
            }
            else
            {
                c=s1[i];
                d=s2[i];
            }
            }
            
        }
        if( (a!=b && a!=d) || (c!=d && c!=b))
        return false;
        return true;
    }
};