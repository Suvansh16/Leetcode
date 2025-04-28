class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long count=0;
        int i=0;
        int j=0;
        long long sum=0;
        int prevj=-1;
        while(j<nums.size())
        {
            if(j!=prevj){
            sum+=nums[j];
            prevj=j;
            }
            if(sum*(j-i+1)<k)
            {
                count+=(j-i+1);
                j++;
            }
            else if(i==j)
            {
                sum-=nums[i];
                i++;
                j++;

            }
            else
            {
                sum-=nums[i];
                i++;
            }
        }
        return count;
    }
};