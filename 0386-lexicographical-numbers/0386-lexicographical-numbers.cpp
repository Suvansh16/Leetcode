class Solution {
public:
void solve(vector<int>&ans,int start,int n)
{
    if(start>n)
    return ;
    ans.push_back(start);
    for(int i=0;i<=9;i++)
    {
        int newno=start*10+i;
        solve(ans,newno,n);
    }
    return ;
}
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        for(int i=1;i<=9;i++)
        {
            solve(ans,i,n);
        }
        return ans;
    }
};