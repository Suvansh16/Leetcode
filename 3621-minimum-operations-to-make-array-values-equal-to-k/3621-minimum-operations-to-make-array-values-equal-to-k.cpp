class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        if(nums[0]<k)
            return -1;
        unordered_set<int>st;
        for(int i:nums)
            st.insert(i);
        int count=0;
        for(auto &i:st)
            {
                if(i!=k)
                    count++;
            }
        return count;
    }
};