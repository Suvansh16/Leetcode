class Solution {
public:
void addbit(vector<int>&v,int number)
{
    for(int i=0;i<32;i++)
    {
        if((number>>i) & 1)
        {
            v[i]++;
        }

    }
}
void removebit(vector<int>&v,int number)
{
    for(int i=0;i<32;i++)
    {
        if((number>>i)&1)
        {
            v[i]--;
        }
    }
}
int vectoint(vector<int>&v)
{
    int number=0;
    for(int i=0;i<32;i++)
    {
        if(v[i]>0)
        {
            number|=(1<<i);
        }
    }
    return number;
}
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int ans=INT_MAX;
        vector<int>v(32,0);
        while(j<nums.size())
        {
            addbit(v,nums[j]);
            while(i<=j && vectoint(v)>=k)
            {
                ans=min(ans,j-i+1);
                removebit(v,nums[i]);
                i++;

            }
            j++;
        }
        return ans==INT_MAX?-1:ans;
    }
};