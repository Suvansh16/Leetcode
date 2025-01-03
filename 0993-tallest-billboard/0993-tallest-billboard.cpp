class Solution {
public:
int t[21][10003];
int solve(vector<int>&rods,int start,int diff)
{
    if(start>=rods.size())
    {
        if(diff==0)
        return 0;
        return INT_MIN;
    }
    if(t[start][diff+5000]!=-1)
    return t[start][diff+5000];
    int skip=solve(rods,start+1,diff);
    int add_in_first=rods[start]+solve(rods,start+1,diff+rods[start]);
    int add_in_second=rods[start]+solve(rods,start+1,diff-rods[start]);
    return t[start][diff+5000]=max({skip,add_in_first,add_in_second});
    
}
    int tallestBillboard(vector<int>& rods) {
        memset(t,-1,sizeof(t));
        return solve(rods,0,0)/2;
    }
};