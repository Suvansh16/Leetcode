class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long ans=0;
        unordered_map<int,int>map;
        for(int i=0,left=0;i<nums.size();i++)
        {
            k-=map[nums[i]]++;
            while(k<=0)
            {
                k+=(--map[nums[left++]]);
            }
            ans+=left;

        }
        return ans;
    }
};