class Solution {
public:
    string sortVowels(string s) {
        priority_queue<int,vector<int>,greater<int>>pq_small;        
        priority_queue<int,vector<int>,greater<int>>pq_large;
        unordered_set<char>st_cap={'A','E','I','O','U'};        
        unordered_set<char>st_small={'a','e','i','o','u'};        

        for(char ch:s)
        {
            if(st_small.find(ch)!=st_small.end())
            pq_small.push(int(ch));
            else if(st_cap.find(ch)!=st_cap.end())
            pq_large.push(int(ch));
        } 

        string t;
        for(char ch:s)
        {
            if(!st_cap.count(ch) && !st_small.count(ch)){
                t.push_back(ch);
            }
            else
            {
                if(!pq_large.empty())
                {
                    t.push_back(char(pq_large.top()));
                    pq_large.pop();
                }
                else
                {
                     t.push_back(char(pq_small.top()));
                    pq_small.pop();
                }
            }
        }
        return t;
    }
};