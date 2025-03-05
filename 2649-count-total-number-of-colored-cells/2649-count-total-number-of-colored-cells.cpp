class Solution {
public:
    long long coloredCells(int n) {
        long long ans=1;
        if(n==1)
        return 1;
        int count=1;
        for(int i=2;i<=n;i++)
        {
            ans+=4*count;
            count++;

        }
        return ans;

    }
};