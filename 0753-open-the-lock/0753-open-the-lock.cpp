class Solution {
public:
void fill_neigh(string start,queue<string>&q,unordered_set<string>&st)
{
    for(int i=0;i<4;i++)
    {
        char a=start[i];
        char dec=a=='0'?'9':a-1;
        char inc=a=='9'?'0':a+1;
        start[i]=dec;
        if(st.find(start)==st.end())
        {
            q.push(start);
            st.insert(start);
        }
        start[i]=inc;
         if(st.find(start)==st.end())
        {
             q.push(start);
            st.insert(start);
        }
        start[i]=a;

    }
}
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>st(deadends.begin(),deadends.end());
        queue<string>q;
        string start="0000";
        if(st.find(start)!=st.end())
        return -1;
        q.push("0000");
        int level=0;
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                string t=q.front();
                q.pop();
                if(t==target)
                return level;
                fill_neigh(t,q,st);
            }
            level++;
        }
        return -1;
    }
};