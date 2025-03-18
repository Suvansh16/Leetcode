class Solution {
public:
bool midpossible(long long mid,vector<int>&ranks,int cars)
{
    long long carsdone=0;
    for(int i=0;i<ranks.size();i++)
    {
        long long c=mid/ranks[i];
        carsdone+=floor(sqrt(c));
    }
    return carsdone>=cars;
}
    long long repairCars(vector<int>& ranks, int cars) {
        long long l=1;
        long long r=1e14;
     
        while(l<r)
        {
            long long mid=(l+r)/2;
            if(midpossible(mid,ranks,cars))
            {
               r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        return l;
    }
};