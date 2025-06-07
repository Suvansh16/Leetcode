class Solution {
public:
typedef pair<char,int> p;
struct comp{
    bool operator()(p&p1,p&p2)
    {
        if(p1.first==p2.first)
        {
            return p1.second<p2.second;
        }
        return p1.first>p2.first;
    }
};
    string clearStars(string s) {
       vector<int>temp(1e5,true);
       priority_queue<p,vector<p>,comp>pq;
       for(int i=0;i<s.length();i++){
        if(s[i]!='*')
        {
            pq.push({s[i],i});
        }
        else
        {
            if(pq.empty())
            {
                temp[i]=false;
            }
            else
            {
                pair<char,int>t=pq.top();
                pq.pop();
                temp[i]=false;
                temp[t.second]=false;
            }
        }
       }
       string ans;
       for(int i=0;i<s.length();i++)
       {
        if(temp[i]!=false)
        {
            ans.push_back(s[i]);
        }
       }
       return ans; 
    }
};