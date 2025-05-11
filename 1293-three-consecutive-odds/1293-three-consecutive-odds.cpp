class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int prev=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]%2!=0)
            prev++;
            else
            prev=0;
            if(prev==3)
            return true;
        }
        return false;
    }
};