class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string,int>map;
        for(int i=0;i<s.length();i++)
        {
            string curr;
            for(int j=i;j<s.length();j++)
            {
                if(curr.empty() ||  curr.back()==s[j])
                {
                    curr.push_back(s[j]);
                    map[curr]++;
                }
                else
                break;
            }

        }
        int maxlength=-1;
        for(auto i:map)
        {
            if(i.second>=3)
            maxlength=max(maxlength,(int)i.first.length());
        }
        return maxlength;
    }
};