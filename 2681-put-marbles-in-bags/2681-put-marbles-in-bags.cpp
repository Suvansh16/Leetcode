class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        priority_queue<long long>pq_max;
        priority_queue<long long ,vector<long long>,greater<long long>>pq_min;
        for(int i=0;i<weights.size()-1;i++)
        {
            pq_max.push(weights[i]+weights[i+1]);
            pq_min.push(weights[i]+weights[i+1]);
        }
        long long max_sum=0;
        long long min_sum=0;
        for(int i=1;i<k;i++)
        {
            max_sum+=pq_max.top();
            pq_max.pop();
            min_sum+=pq_min.top();
            pq_min.pop();
        }
        return max_sum-min_sum;
    }
};