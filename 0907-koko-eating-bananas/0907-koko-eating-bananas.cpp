class Solution {
public:
int check(vector<int>&piles,int mid)
{
    long long  ans=0;
    for(int i=0;i<piles.size();i++)
    {
         ans += (piles[i] + mid - 1) / mid;
         if (ans > INT_MAX) return INT_MAX;
       
    }
    return ans;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int i=1;
        int j=*max_element(piles.begin(),piles.end());
        int ans=-1;
        while(i<=j)
        {
            int mid=i+(j-i)/2;
            int l=check(piles,mid);
            if(l<=h)
            {
                ans=mid;
               
                j=mid-1;
            }
            else
            i=mid+1;
        }
        return ans;
    }
};