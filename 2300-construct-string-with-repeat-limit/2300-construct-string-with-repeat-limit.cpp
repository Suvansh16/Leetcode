class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pair<char,int>>p;
        vector<int>a(26,0);
        for(char &c:s)
        {
            a[c-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(a[i]>0)
            p.push({'a'+i,a[i]});
        }
        string res;
        while(!p.empty())
        {
            pair<char,int>pa=p.top();
            p.pop();
            int l=repeatLimit;
            int m=min(l,pa.second);
            while(m--)
            {
                res.push_back(pa.first);

            }
            if(pa.second-l>0 && !p.empty())
            {
               
                pair<char,int>s=p.top();
                p.pop();
                 res.push_back(s.first);
                s.second-=1;
                if(s.second>0)
               p.push({s.first,s.second});
                p.push({pa.first,pa.second-l});
            }
        }
        return res;
    }
};