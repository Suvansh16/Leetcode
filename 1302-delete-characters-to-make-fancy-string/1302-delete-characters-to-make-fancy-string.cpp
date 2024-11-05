class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        char prev='@';
        int count=0;
        for(int i=0;i<s.length();i++)
        {
           if(prev==s[i])
           count++;
           else if(prev!=s[i])
           {
            if(count>0)
            {
                int sum=0;
                while(sum!=2  && count!=0)
            {
                ans.push_back(prev);
                count--;
                sum++;
            }

            }
            prev=s[i];
            count=1;
           }

        }
         int sum=0;
                while(sum!=2  && count!=0)
            {
                ans.push_back(prev);
                count--;
                sum++;
            }
        return ans;
    }
};