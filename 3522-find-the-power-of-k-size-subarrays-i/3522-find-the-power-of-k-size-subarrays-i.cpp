class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int i=0;
        int j=k-1;
        int num=-1;
        vector<int>ans;
       bool check=false;
        while(j<nums.size())
        {
            if(check==false)
            {
                bool val=false;
                for(int a=i+1;a<=j;a++)
                {
                    if(nums[a]<=nums[a-1] || nums[a]!=nums[a-1]+1){
                    ans.push_back(-1);
                    val=true;
                    break;
                    }
                }
                if(val==false)
                {
                    check=true;
                   if(k>1)
                   num=nums[j];
                   else
                   num=-1;
                    ans.push_back(nums[j]);
                }
            }
           else if(check==true)
           {
            if(nums[j]==num+1 || k==1)
            {
                num=nums[j];
                ans.push_back(num);
            }
            else
            {
                ans.push_back(-1);
                check=false;
                
            }
           
           }
            i++;j++;
        }
        return ans;
    }
};