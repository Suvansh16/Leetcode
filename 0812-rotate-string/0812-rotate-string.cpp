class Solution {
public:
    bool rotateString(string s, string goal) {
        int ind;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==goal[0]){
            ind=i;
             string l=s.substr(ind);
        l+=s.substr(0,ind);
        if(l==goal)
        return true;
            }
        }
       
        return false;

    }
};