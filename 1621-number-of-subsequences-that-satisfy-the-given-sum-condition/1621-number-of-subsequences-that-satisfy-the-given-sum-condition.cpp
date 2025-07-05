class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        int mod=1e9+7;
        sort(nums.begin(),nums.end());
        vector<int>powers(n,1);
        for(int i=1;i<n;i++){
            powers[i]=(powers[i-1]*2)%mod;
        }
        int left=0;
        int right=n-1;
        int ans=0;
        while(left<=right)
        {
            if(nums[left]+nums[right]<=target)
            {
                ans=(ans%mod+powers[right-left]%mod)%mod;
                left++;
            }
            else
            right-=1;
        }
        return ans;
    }
};