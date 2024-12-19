class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxtillnow=-1;
        int count=0;
        for(int i=0;i<arr.size();i++)
        {
            maxtillnow=max(maxtillnow,arr[i]);
            if(maxtillnow==i)
            count++;
        }
        return count;
    }
};