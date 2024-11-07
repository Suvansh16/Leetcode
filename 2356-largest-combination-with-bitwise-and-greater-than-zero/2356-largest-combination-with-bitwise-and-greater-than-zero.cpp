class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans=0;
       for(int i=0;i<24;i++)
       {
        int count=0;
        for(int j=0;j<candidates.size();j++)
        {
            string a=bitset<24>(candidates[j]).to_string();
            if(a[i] & 1)
            count++;   
        }
        ans=max(ans,count);
       }
       return ans;
    }
};