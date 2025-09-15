class Solution {
public:
void update(int i,int l,int r,int update_idx,vector<long long>&seg)
{
    if(l==r)
    {
        seg[i]=1;
        return;
    }
    int mid=(l+r)/2;
    if(update_idx<=mid)
    {
        update(2*i+1,l,mid,update_idx,seg);
    }
    else
    {
        update(2*i+2,mid+1,r,update_idx,seg);
    }
    seg[i]=seg[2*i+1]+seg[2*i+2];
}
long long query(int start,int end,int i,int l,int r,vector<long long>&seg)
{
    if(r<start || l>end)
    return 0;
    if(l>=start && r<=end)
    return seg[i];
    int mid=(l+r)/2;
    long long left=query(start,end,2*i+1,l,mid,seg);
    long long right=query(start,end,2*i+2,mid+1,r,seg);
    return left+right;
}
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>map;
       for(int i=0;i<nums2.size();i++)
       {
        map[nums2[i]]=i;
       }
       int n=nums1.size();
       vector<long long >seg(4*n);
       long long result=0;
       update(0,0,n-1,map[nums1[0]],seg);
       for(int i=1;i<n;i++)
       {
        int idx=map[nums1[i]];
        long long left_common=query(0,idx,0,0,n-1,seg);
        long long left_not_common=i-left_common;
        long long elements_after_idx=(n-1)-idx;
        long long right_common=elements_after_idx-left_not_common;
        result+=left_common*right_common;
        update(0,0,n-1,idx,seg);
       }
       return result;

    }
};