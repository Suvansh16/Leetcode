class Solution {
public:
void solve(int n,vector<int>&ans,int start)
{
   if(start>n)
   return;
   ans.push_back(start);
   for(int i=0;i<=9;i++)
   {
    int newno=start*10+i;
    // if(start>n)
    // return;
    solve(n,ans,newno);

   }
}
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
       for(int i=1;i<=9;i++)
       {
        solve(n,ans,i);
       }
       return ans;

    }
};
