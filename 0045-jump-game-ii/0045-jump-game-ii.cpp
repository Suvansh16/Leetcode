class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int>arr;
        int maxi=0;
        for(int i=0;i<nums.size();i++)
        {
            maxi=max(nums[i]+i,maxi);
            arr.push_back(maxi);
        }
        int count=0;
        int i=0;
        while(i<=nums.size())
        {
            if(arr[i]>=nums.size()-1)
            {
                
                break;
            }
            count++;
            int l=arr[i];
            i=l;
        }
        if(i<nums.size()-1)
        count++;
        return count;

    }
};