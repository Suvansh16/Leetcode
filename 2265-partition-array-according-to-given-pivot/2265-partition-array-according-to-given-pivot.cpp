class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int count=0;
        vector<int>less;
        vector<int>more;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>pivot)
            {
                more.push_back(nums[i]);
            }
            else if(nums[i]<pivot)
            {
                less.push_back(nums[i]);
            }
            else
            {
                count++;
            }
        }
        vector<int>result;
        for(int i=0;i<less.size();i++)
        result.push_back(less[i]);
        while(count--)
        result.push_back(pivot);
        for(int i=0;i<more.size();i++)
        result.push_back(more[i]);
        return result;
        
    }
};