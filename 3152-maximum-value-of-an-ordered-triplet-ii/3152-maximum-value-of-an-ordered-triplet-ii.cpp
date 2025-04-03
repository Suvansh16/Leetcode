class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        if(nums.size()<3)
        return 0;
        long long bestdiff=LLONG_MIN;
        long long ans=LLONG_MIN;
        long long maxi=nums[0];
        for(long long j=1;j<nums.size()-1;j++)
        {
            bestdiff=max(bestdiff,maxi-(long long)nums[j]);
            ans=max(ans,bestdiff*(long long)nums[j+1]);
            maxi=max(maxi,(long long)nums[j]);
        }
        return ans>=0?ans:0;
    }
};