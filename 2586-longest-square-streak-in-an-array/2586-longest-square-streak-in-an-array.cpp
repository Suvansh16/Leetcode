class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int>map;
        int maxi=1;
        for(int i=0;i<nums.size();i++)
        {
            int a=(int)sqrt(nums[i]);
            if(a*a==nums[i] && map.find(a)!=map.end())
            {
                map[nums[i]]=map[a]+1;
               
            }
            else
            map[nums[i]]=1;
             maxi=max(maxi,map[nums[i]]);
        }
        return maxi==1?-1:maxi;

    }
};