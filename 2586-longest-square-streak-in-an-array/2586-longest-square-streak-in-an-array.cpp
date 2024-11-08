class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int maxstreak=0;
        unordered_set<int>st(nums.begin(),nums.end());
        for(int &num:nums)
        {
            int currstreak=0;
            long long curr=num;
            while(st.find(curr)!=st.end())
            {
                currstreak+=1;
                if(curr*curr>1e5)
                break;
                curr=curr*curr;
            }
            maxstreak=max(maxstreak,currstreak);
        }
        return maxstreak==1?-1:maxstreak;
    }
};