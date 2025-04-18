class Solution {
public:
    string countAndSay(int n) {
        string ans="1";
        while(--n)
        {
            cout<<ans<<endl;
            string t;
            int ele=-1;
            int count=0;
            for(int i=0;i<ans.length();i++)
            {
                if(ele==-1 || (ans[i]-'0')==ele)
                {
                    ele=ans[i]-'0';
                    count++;
                }
                else
                {
                    string a=to_string(count);
                    t+=a;
                    string b=to_string(ele);
                    t+=b;
                    count=1;
                    ele=ans[i]-'0';
                }
               
            }
            if(ele!=-1)
            {
                string a=to_string(count);
                    t+=a;
                    string b=to_string(ele);
                    t+=b;
            }
            ans=t;
        }
        return ans;
    }
};