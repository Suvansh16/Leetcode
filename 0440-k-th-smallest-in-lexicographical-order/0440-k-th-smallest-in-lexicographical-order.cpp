class Solution {
public:
int countprefix(long prefix,int n)
{
    long curr=prefix,next=prefix+1;
    long count=0;
    while(curr<=n)
    {
        count+=min((long)n+1,next)-curr;
        curr*=10;
        next*=10;
    }
    return count;
}
    int findKthNumber(int n, int k) {
        int curr=1;
        k--;
        while(k>0)
        {
            int count=countprefix(curr,n);
            if(count<=k)
            {
                k-=count;
                curr+=1;
            }
            else
            {
                curr*=10;
                k-=1;
            }
        }
        return curr;

    }
};