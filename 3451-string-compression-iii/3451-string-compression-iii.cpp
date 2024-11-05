class Solution {
public:
    string compressedString(string word) {
        char prev='@';
        int count=0;
        string comp;
        for(int i=0;i<word.size();i++)
        {
            if(word[i]==prev)
            count++;
            if(word[i]!=prev)
            {
                if(count>0)
                {
                    int a=count/9;
                    int b=count%9;
                    while(a--)
                    {
                        comp.push_back('9');
                        comp.push_back(prev);
                    }
                    if(b>0){
                    comp+=to_string(b);
                        comp.push_back(prev);
                    }
                    
                }
                prev=word[i];
                count=1;
            }
        }
                    int a=count/9;
                    int b=count%9;
                    while(a--)
                    {
                        comp.push_back('9');
                        comp.push_back(prev);
                    }
                    if(b>0){
                    comp+=to_string(b);
                        comp.push_back(prev);
                    }
        return comp;
    }
};