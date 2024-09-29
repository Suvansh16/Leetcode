class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>map;
        unordered_map<char,int>map2;
        int count=1;
        int k=2;
        for(int i=0;i<word.length();i++)
        map2[word[i]]++;
        auto lambda=[&](char &ch1,char &ch2)
        {
            return map2[ch1]>map2[ch2];
        };
        sort(word.begin(),word.end(),lambda);
        
        for(int i=0;i<word.length();i++)
        {
            if(k==10)
            {
                count++;
                k=2;
            }
            if(map.find(word[i])==map.end())
            {
                k++;
                map[word[i]]=count;
            }
        }
        int result=0;
        for(int i=0;i<word.length();i++)
        {
            result+=map[word[i]];
        }
        return result;
    }
};