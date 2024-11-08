class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int>ans;
        int n=nums.size();
        int exor=0;
        for(int i=0;i<n;i++)
        {
            exor^=nums[i];
        }
        int t=(1<<maximumBit)-1;
        while(n--)
        {
           ans.push_back(exor^t);
            exor^=nums[n];
        }
        return ans;
    }
};