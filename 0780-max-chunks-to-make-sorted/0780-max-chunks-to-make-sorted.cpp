class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int cumulative_sum=0;
        int cumsum_orig=0;
        int cunk=0;
        for(int i=0;i<arr.size();i++)
        {
            cumulative_sum+=arr[i];
            cumsum_orig+=i;
            if(cumulative_sum==cumsum_orig)
            cunk++;
        }
        return cunk;
    }
};