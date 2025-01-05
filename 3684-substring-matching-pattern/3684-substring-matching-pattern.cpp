class Solution {
public:
    bool hasMatch(string s, string p) {
        string s1, s2;
        int l = -1; // Position of '*' in pattern
        
        // Split pattern into s1 (before '*') and s2 (after '*')
        for (int i = 0; i < p.length(); i++) {
            if (p[i] == '*') {
                l = i;
                break;
            }
            s1.push_back(p[i]);
        }
        
        if (l != -1) { // If '*' exists, extract s2
            for (int i = l + 1; i < p.length(); i++) {
                s2.push_back(p[i]);
            }
        }
        
        // Handle special cases
        if (s1.empty()) s1 = ""; // Match anything at the start
        if (s2.empty()) s2 = ""; // Match anything at the end
        bool a=false;
        int lt=-1;
        if(!s1.empty()){
        for(int i=0;i<s.length()-s1.length()+1;i++)
            {
                if(s.substr(i,s1.length())==s1){
                    a=true;
                    lt=i;
                    break;
                }
                    
            }
        }
            else if(s1.empty())
            a=true;
        if(a==false)
            return false;
        bool m=false;
        if(!s2.empty() )
        {
            if(lt==-1)
            lt=0;
            else 
            lt=lt+s1.length();
            for(int i=lt;i<s.length()-s2.length()+1;i++)
            {
                if(s.substr(i,s2.length())==s2){
                    m=true;
                   
                    break;
                }
                    
            }
        }
        else if(s2.empty())
        {
            m=true;
        }
        return m==true?true:false;
    }
};