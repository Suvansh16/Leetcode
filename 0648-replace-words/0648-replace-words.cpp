class Solution {
public:
string findwords(string word,unordered_set<string>temp)
{
    for(int i=0;i<word.length();i++)
    {
        string ans=word.substr(0,i);
        if(temp.count(ans))
        return ans;
    }
    return word;
}
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string>temp(dictionary.begin(),dictionary.end());
        stringstream ss(sentence);      
        string word;
        string result;
        while(getline(ss,word,' '))
        {
            result+=findwords(word,temp)+ " ";
        }
        result.pop_back();
        return result;
    }
};