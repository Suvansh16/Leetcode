class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int count=0;
        for(int i=0;i<sentence.length();i++)
        {
            if(sentence[i]==' '){
            count++;
            continue;
            }
            string a;
            
            while(i<sentence.length() && sentence[i]!=' '  )
            {
                a.push_back(sentence[i]);
                i++;
            }
            if(a.length()<searchWord.length()){count++;
            continue;
            }
            if(a.substr(0,searchWord.length())==searchWord)
            return count+1;
            count++;

        }
        return -1;
    }
};