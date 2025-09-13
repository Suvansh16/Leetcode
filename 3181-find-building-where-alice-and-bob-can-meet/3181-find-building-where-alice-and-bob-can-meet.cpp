class Solution {
public:
int n,m;
void build(vector<int>&seg,vector<int>&heights,int i,int l,int r)
{
    if(l==r)
    {
        seg[i]=l;
        return ;
    }
    int mid = l + (r - l) / 2;
    build(seg,heights,2*i+1,l,mid);
    build(seg,heights,2*i+2,mid+1,r);
    int left=heights[seg[2*i+1]];
    int right=heights[seg[2*i+2]];
    if(left>=right)
    seg[i]=seg[2*i+1];
    else
    {
        seg[i]=seg[2*i+2];
    }
    return ;
}
int find_max(int i,int l,int r,int start,int end,vector<int>&seg,vector<int>&heights)
{
    if(l>end || r<start)
    return -1;
    else if(l>=start && r<=end)
    return seg[i];
    else 
    {
         int mid = l + (r - l) / 2;
        int t=find_max(2*i+1,l,mid,start,end,seg,heights);
        int q=find_max(2*i+2,mid+1,r,start,end,seg,heights);
        if(t==-1)
        return q;
        if(q==-1)
        return t;
        if(heights[t]>=heights[q])
        {
            return t;
        }
        else
        {
            return q;
        }
    }
}
int RMIQ(vector<int>&seg,vector<int>&heights,int n,int a,int b)
{
    return find_max(0,0,n-1,a,b,seg,heights);
}
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        n=heights.size();
        m=queries.size();
        vector<int>seq(4*heights.size());
        build(seq,heights,0,0,n-1);
        vector<int>ans;
       for(auto query:queries)
       {
        int alice=min(query[0],query[1]);
        int bob=max(query[0],query[1]);
        if(alice==bob || heights[bob]>heights[alice]){
        ans.push_back(bob);
        continue;
       }
       int l=bob+1;
       int r=n-1;
       int result_idx=INT_MAX;
       while(l<=r)
       {
        int mid = l + (r - l) / 2;
        int idx=RMIQ(seq,heights,n,l,mid);
        if(heights[idx]>max(heights[alice],heights[bob]))
        {
            r=mid-1;
            result_idx=min(result_idx,idx);

        }
        else
        {
            l=mid+1;
        }
       }
       if(result_idx==INT_MAX)
       {
        ans.push_back(-1);

       }
       else
       {
        ans.push_back(result_idx);
       }

       }
        return ans;
    }
};