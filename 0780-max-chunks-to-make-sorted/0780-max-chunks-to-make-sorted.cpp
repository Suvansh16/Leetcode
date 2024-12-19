class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int>prefix_max(arr.begin(),arr.end());
        vector<int>suffix_min(arr.begin(),arr.end());
        for(int i=1;i<arr.size();i++)
        {
            prefix_max[i]=max(prefix_max[i],prefix_max[i-1]);

        }
        for(int i=arr.size()-2;i>=0;i--)
        {
            suffix_min[i]=min(suffix_min[i+1],suffix_min[i]);
        }
        int cunk=0;
        for(int i=0;i<arr.size();i++)
        {
            int prefix=i>0?prefix_max[i-1]:-1;
            int suffix=suffix_min[i];
            if(prefix<suffix)
            cunk++;
        }
        return cunk;
    }
};