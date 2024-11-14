class Solution {
public:
bool possibletodis(int  mid,vector<int>&quant,int n)
{

    for(int i=0;i<quant.size();i++)
    {
        n-=(quant[i] + mid - 1) / mid;//alternative to ceil
        if(n<0)
        return false;
    }
    return true;

    
}
    int minimizedMaximum(int n, vector<int>& quantities) {
         int  l=1;
        int  r= *max_element(quantities.begin(),quantities.end());
        int  ans;
        while(l<=r)
        {
           int mid=l+(r-l)/2;
           if(possibletodis(mid,quantities,n))
           {
            ans=mid;
            r=mid-1;

           }
           else
           l=mid+1;
           
        }
        return ans;

    }
};