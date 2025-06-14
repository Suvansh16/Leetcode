class Solution {
public:
    int minMaxDifference(int num) {
        string t=to_string(num);
        int size=t.length();
        int pos=-1;
        for(int i=0;i<size;i++)
        {
            if(t[i]-'0'!=9)
           { 
            pos=i;
            break;
           }
        } 
          string maxi;
          int digit;
        if(pos!=-1) {  
        digit=t[pos]-'0';

      
        for(int i=0;i<size;i++)
        {
            if(t[i]-'0'==digit)
            maxi.push_back('9');
            else
            maxi.push_back(t[i]);
        }}
        else
        maxi=t;
        digit=t[0]-'0';
        string mini;
        for(int i=0;i<size;i++)
        {
            if(t[i]-'0'==digit)
            mini.push_back('0');
            else
            mini.push_back(t[i]);
        }
        cout<<maxi<<"  "<<mini<<" ";
        return stoll(maxi)-stoll(mini);

    }
};