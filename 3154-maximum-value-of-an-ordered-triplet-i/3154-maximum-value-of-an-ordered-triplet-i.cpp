class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans=INT_MIN;
        for(int i=0;i<nums.size()-2;i++)
        {
            int a=nums[i];
            for(int j=i+1;j<nums.size()-1;j++)
            {
                int b=nums[j];
                for(int k=j+1;k<nums.size();k++)
                {
                    long long d=a-b;
                    long long c=d*(long long)nums[k];
                    ans=max(ans,c);
                }
            }
        }
        return ans>=0?ans:0;
    }
};