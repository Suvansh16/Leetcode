class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>map;
        unordered_map<char,int>temp;
        for(char ch:word)
        map[ch]++;
        auto lambda=[&](char &a,char &b)
        {
            return map[a]>map[b];
        };

        sort(word.begin(),word.end(),lambda);
        int count=1;
        int result=0;
        int k=2;
        for(char ch:word)
        {
            if(temp.find(ch)!=temp.end())
            continue;
            else
            {
                if(k>9)
                {
                    count++;
                    k=2;

                }
                k++;
                temp[ch]=count;
               
            }

        }
        for(char ch:word)
        {
            result+=temp[ch];
        }
        return result;
    }
};