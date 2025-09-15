class Solution {
public:
int n;

void build(int i,int l,int r,vector<int>&seg,vector<int>&baskets)
{
    if(l==r)
    {
        seg[i]=baskets[l];
        return ;
    }
    int mid=(l+r)/2;
    build(2*i+1,l,mid,seg,baskets);
    build(2*i+2,mid+1,r,seg,baskets);
    seg[i]=max(seg[2*i+2],seg[2*i+1]);
    return ;
}
bool query(int i,int val,int l,int r,vector<int>&seg)
{
    if(seg[i]<val)
    return false;
    if(l==r)
    {
        seg[i]=-1;
        return true;
    }
    bool placed=false;
    int mid=(l+r)/2;
    if(seg[2*i+1]>=val)
    {
        
        placed=query(2*i+1,val,l,mid,seg);
    }
    else
    {
        placed=query(2*i+2,val,mid+1,r,seg);
    }
    seg[i]=max(seg[2*i+1],seg[2*i+2]);
    return placed;
}
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        n=baskets.size();
        vector<int>seg(4*n);
        build(0,0,n-1,seg,baskets);
        int unplaced=0;
        for(int i:fruits)
        {
            
            if(!query(0,i,0,n-1,seg))
            unplaced++;
        }
        return unplaced;
    }
};