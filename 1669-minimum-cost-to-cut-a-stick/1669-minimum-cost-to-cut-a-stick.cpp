class Solution {
public:
int t[103][103];
int solve(vector<int>&cuts,int left,int right)
{
    if(right-left==1)
    return 0;
    if(t[left][right]!=-1)
    return t[left][right];
    int result=INT_MAX;
    for(int i=left+1;i<=right-1;i++)
    {
        int cost=solve(cuts,left,i)+solve(cuts,i,right)+(cuts[right]-cuts[left]);
        result=min(result,cost);
    }
    return t[left][right]=result;
}
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.insert(begin(cuts),0);
        cuts.push_back(n);
        memset(t,-1,sizeof(t));
        return solve(cuts,0,cuts.size()-1);
    }
};