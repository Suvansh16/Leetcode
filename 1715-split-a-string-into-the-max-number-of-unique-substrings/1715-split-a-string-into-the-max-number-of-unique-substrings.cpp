class Solution {
public:

void solve(unordered_set<string>&temp,int currcount,int &maxcount,int start,string s)
{
    if(start>=s.length())
    {
        maxcount=max(maxcount,currcount);
        return;
    }
    for(int j=start;j<s.length();j++)
    {
        string sub=s.substr(start,j-start+1);
        if(temp.find(sub)==temp.end())
        {
            temp.insert(sub);
            solve(temp,currcount+1,maxcount,j+1,s);
            temp.erase(sub);
        }
    }
}
    int maxUniqueSplit(string s) {
        int currcount=0;
        int maxcount=0;
        int i=0;
        unordered_set<string>temp;
        solve(temp,currcount,maxcount,i,s);
        return maxcount;
    }
};