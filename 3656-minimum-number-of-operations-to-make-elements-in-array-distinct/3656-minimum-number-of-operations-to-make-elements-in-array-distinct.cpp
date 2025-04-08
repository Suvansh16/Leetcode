class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int>map;
        for(int &i:nums)
        map[i]++;
        int count=0;
        
        if(nums.size()==map.size())
        return count;
        int i=0;
        while(i<nums.size() && (nums.size()-i)!=map.size())
        {
            map[nums[i]]--;
            if(map[nums[i]]==0)
            map.erase(nums[i]);
            i++;
            if(i<nums.size()){
            map[nums[i]]--;
             if(map[nums[i]]==0)
            map.erase(nums[i]);
            i++;
            }
            if(i<nums.size()){
            map[nums[i]]--;
             if(map[nums[i]]==0)
            map.erase(nums[i]);
            i++;
            }
            count++;
        }
        return count;
    }
};