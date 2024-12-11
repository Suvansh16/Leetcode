class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector<pair<int,int>>intervals;
        for(int i=0;i<nums.size();i++)
        {
            intervals.push_back({nums[i]-k,nums[i]+k});

        }

        sort(intervals.begin(),intervals.end());

        deque<pair<int,int>>dq;
        int countmax=0;
        for(auto i:intervals)
        {
            while(!dq.empty() && dq.front().second<i.first)
            {
                dq.pop_front();
            }
            dq.push_back({i.first,i.second});
            countmax=max(countmax,(int)dq.size());
        }
        return countmax;
    }
};