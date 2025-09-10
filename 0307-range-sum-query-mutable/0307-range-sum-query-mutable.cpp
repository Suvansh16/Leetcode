class NumArray {
public:
vector<int>v;
int n;
void build_tree(vector<int>&v,int i,int l,int r,vector<int>&nums)
{
    if(l==r)
    {
        v[i]=nums[l];
        return ;

    }
int mid=(l+r)/2;
build_tree(v,2*i+1,l,mid,nums);
build_tree(v,2*i+2,mid+1,r,nums);
v[i]=v[2*i+1]+v[2*i+2];
return ;
}
void update_ele(int ind,int val,int i,int l,int r,vector<int>&v)
{
    if(l==r)
    {
        v[i]=val;
        return ;
    }
int mid=(l+r)/2;
if(ind<=mid)
{
    update_ele(ind,val,2*i+1,l,mid,v);
}
else
update_ele(ind,val,2*i+2,mid+1,r,v);
v[i]=v[2*i+1]+v[2*i+2];

}
int sum_ele(int start,int end,int i,int l,int r,vector<int>&v)
{
    if(l>end || r<start)
    return 0;
    else if(l>=start && r<=end)
    return v[i];
    else{
        int mid=(l+r)/2;
        return sum_ele(start,end,2*i+1,l,mid,v)+sum_ele(start,end,2*i+2,mid+1,r,v);
    }

}
    NumArray(vector<int>& nums) {
         n=nums.size();
       v.resize(4*n);
        build_tree(v,0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        update_ele(index,val,0,0,n-1,v);
    }
    
    int sumRange(int left, int right) {
        return sum_ele(left,right,0,0,n-1,v);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */