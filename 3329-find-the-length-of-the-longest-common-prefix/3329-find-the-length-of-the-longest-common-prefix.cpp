class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int>st;
        for(int i=0;i<arr1.size();i++)
        {
            int a=arr1[i];
            while(a)
            {
                st.insert(a);
                a/=10;
            }
        }
        int maxans=0;
        for(int i=0;i<arr2.size();i++)
        {
            int a=arr2[i];
            while(a)
            {
                if(st.count(a))
                {
                    int val=floor(log10(a))+1;
                    maxans=max(maxans,val);
                    break;
                }
                a/=10;
            }
        
        }
        return maxans;
    }
};