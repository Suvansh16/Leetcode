class Solution {
public:
void add(int a,long long &b)
{
    while(a!=0)
    {
        b+=a;
        a-=1;
    }

}
    long long zeroFilledSubarray(vector<int>& nums) {
        int count=0,prev=-1;
        long long  sum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                if(prev==0)
                count++;
                else
                {
                    prev=0;
                    count=1;
                }
            }
            else{
            add(count,sum);
            prev=nums[i];
            count=0;
            }
        }
         add(count,sum);
        return sum;
    }
};