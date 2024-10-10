class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int>s;
        for(int i=0;i<nums.size();i++)
        {
            if(s.empty() || nums[s.top()]>nums[i])
            {
                s.push(i);
            }
        }
        int n=nums.size();
        int maxi=-1;
        for(int i=n-1;i>0;i--)
        {
            
            while(!s.empty() && nums[i]>=nums[s.top()])
            {
               maxi=max(maxi,i-s.top());
               s.pop();        
            }
            

        }
        return maxi;
    }
};