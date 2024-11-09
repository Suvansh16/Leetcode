class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>st;
        for(int a:nums)
        {
            st.insert(a);
        }
        int i=0;
        for(auto &a:st)
        {
            nums[i]=a;
            i++;
        }
        
        return st.size();
    }
};