class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        unordered_map<int,int>map;
        int result=0;
        int left=0;
        for(int i=0;i<nums.size();i++)
        {
            map[nums[i]]++;
            while(map.size()==st.size())
            {
                result+=nums.size()-i;
                map[nums[left]]--;
                if(map[nums[left]]==0)
                {
                    map.erase(nums[left]);
                }
                left++;
            }
        }
        return result;
    }
};