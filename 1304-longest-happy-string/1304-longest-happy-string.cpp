class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        if(a>0)
        pq.push({a,'a'});
        if(b>0)
        pq.push({b,'b'});
        if(c>0)
        pq.push({c,'c'});
        string result="";
        while(!pq.empty())
        {
            pair<int,char>p=pq.top();
            pq.pop();
            if(result.length()>=2 && result[result.length()-1]==p.second && result[result.length()-2]==p.second)
            {
                if(pq.empty())
                break;
                pair<int,char>p2=pq.top();
                pq.pop();
                result.push_back(p2.second);
                p2.first-=1;
                if(p2.first)
                {
                    pq.push({p2.first,p2.second});
                }
                pq.push({p.first,p.second});
            }
            else
            {
                result.push_back(p.second);
                p.first-=1;
                if(p.first>0)
                pq.push({p.first,p.second});
            }
        }
        return result;
    }
};