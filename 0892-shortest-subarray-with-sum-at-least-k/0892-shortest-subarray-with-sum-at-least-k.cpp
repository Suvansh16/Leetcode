class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        vector<long long>cum_sum(nums.size(),0);
        deque<int>dq;
        long long sum=0;
        int result=INT_MAX;
        int j=0;
        while(j<nums.size())
        {
            sum+=nums[j];
            cum_sum[j]=sum;
            if(sum>=k)
            {
                result=min(result,j+1);
            }
            while(!dq.empty() && cum_sum[j]-cum_sum[dq.front()]>=k)
            {
                result=min(result,j-dq.front());
                dq.pop_front();
            }
            while(!dq.empty() && cum_sum[dq.back()]>=cum_sum[j])
            {

                dq.pop_back();
            }
            dq.push_back(j);
            j++;


        }
        return result==INT_MAX?-1:result;
    }
};