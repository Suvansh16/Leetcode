class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int>v(s.length(),0);
        int n=s.length();
        for(vector<int>&a:shifts)
        {
            if(a[2]==1)
            {
            v[a[0]]++;
            if(a[1]+1<n)
            v[a[1]+1]--;
            }
            else
            { 
                v[a[0]]--;
                 if(a[1]+1<n)
                 v[a[1]+1]++;
            
            }
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=v[i];
            v[i]=sum%26;
            
            
        }
        for(int i=0;i<n;i++)
        {
            int shift=v[i];
            int newchar=(s[i]-'a'+26+shift)%26;
            s[i]='a'+newchar;
        }
        return s;
    }
};