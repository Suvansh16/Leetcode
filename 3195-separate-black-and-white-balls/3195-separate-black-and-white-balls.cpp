class Solution {
public:
    long long minimumSteps(string s) {
        int a=0;
        int b=s.length()-1;
        long long count=0;
        while(a<b)
        {
            while(b>=0 && s[b]=='1')
            b--;
            while(a<s.length() && s[a]=='0')
            a++;
            if(b>a){
            count+=(b-a);
            a++;
            b--;
            }
        }
        return count;
    }
};