class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.length()<s2.length())
        swap(s1,s2);
        stringstream ss1(s1);
        stringstream ss2(s2);
        deque<string>d1;
        deque<string>d2;
        string token1;
        string token2;
        while(ss1>>token1)
        {
            d1.push_back(token1);
        }
         while(ss2>>token2)
        {
            d2.push_back(token2);
        }
        while(!d1.empty() && !d2.empty() && d1.front()==d2.front())
        {
            d1.pop_front();
            d2.pop_front();
        }
        while(!d1.empty() && !d2.empty() && d1.back()==d2.back())
        {
            d2.pop_back();
            d1.pop_back();
        }
        return d2.empty();
    }
};