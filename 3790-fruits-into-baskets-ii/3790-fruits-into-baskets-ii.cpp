
class Solution {
public:
void build(int i,int l,int r,vector<int>&seg,vector<int>&heights)
{
    if(l==r)
    {
        seg[i]=heights[l];
        return ;
    }
    int mid=(l+r)/2;
    build(2*i+1,l,mid,seg,heights);
    build(2*i+2,mid+1,r,seg,heights);
    seg[i]=max(seg[2*i+1],seg[2*i+2]);
}
bool query(int i,int l,int r,vector<int>&seg,int val)
{
    if(seg[i]<val)
    return false;
    if(l==r)
    {
        seg[i]=-1;
        return true;

    }
    int mid=(l+r)/2;
    bool placed=false;
    if(seg[2*i+1]>=val)
    {
        placed=query(2*i+1,l,mid,seg,val);   
    }
    else
    {
        placed=query(2*i+2,mid+1,r,seg,val);
    }
    seg[i]=max(seg[2*i+1],seg[2*i+2]);
    return placed;
}
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        vector<int>seg(4*baskets.size(),-1);
        build(0,0,baskets.size()-1,seg,baskets);
        int unplaced=0;
        for(int i:fruits)
        {
            if(!query(0,0,baskets.size()-1,seg,i))
            unplaced++;
        }
        return unplaced;
    }
};