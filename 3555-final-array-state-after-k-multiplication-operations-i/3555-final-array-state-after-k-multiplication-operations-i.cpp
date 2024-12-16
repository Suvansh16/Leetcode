class Solution {
public:
typedef pair<int,int> p;
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<p,vector<p>,greater<p>>pq;
        int l=0;
        for(int &num:nums)
        pq.push({num,l++});
        while(k--)
        {
            pair<int,int>m=pq.top();
            pq.pop();
            pq.push({m.first*multiplier,m.second});
            nums[m.second]*=multiplier;
        }
        return nums;
    }
};