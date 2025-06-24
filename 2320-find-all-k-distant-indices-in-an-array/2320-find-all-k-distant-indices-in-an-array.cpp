class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int>ans;
        int size=nums.size()-1;
        for(int i=0;i<nums.size();i++)
        {
            bool v=false;
            for(int j=i;j<=(min(size,i+k));j++)
            {
                if(nums[j]==key){
                ans.push_back(i);
                v=true;
                break;
                }

            }
            if(!v){
                for(int j=i;j>=max(0,i-k);j--)
                {
                     if(nums[j]==key){
                        ans.push_back(i);
                        v=true;
                        break;
                             }
                }
                 }}
        return ans;
    }
};