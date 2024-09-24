class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        long long sum1=0;
        long long sum2=0;
        int i=0;
        int n=piles.size();
        int l=n-1;
        int m=0;
        while(i!=n)
        {
            if(i%2==0)
            {
                sum1+=max(piles[l],piles[m]);
                if(piles[m]>=piles[l])
                {
                    m++;
                    
                }
                else
                {
                    l--;
                }
            }
            else{
               sum2+=min(piles[l],piles[m]);
                if(piles[m]>piles[l])
                {
                    m++;
                    
                }
                else
                {
                    l--;
                }

            }
            i++;
        }
        return sum1>sum2;
    }
};