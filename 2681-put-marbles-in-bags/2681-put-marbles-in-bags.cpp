class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<long long>sum_vec;
        for(int i=0;i<weights.size()-1;i++)
        {
            sum_vec.push_back(weights[i]+weights[i+1]);
        }
        sort(sum_vec.begin(),sum_vec.end());
        long long min_sum=accumulate(sum_vec.begin(),sum_vec.begin()+(k-1),0LL);
        long long max_sum=accumulate(sum_vec.end()-(k-1),sum_vec.end(),0LL);
        return max_sum-min_sum;
    }
};