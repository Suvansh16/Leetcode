class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain=[](int p,int t)
        {
            return (double)(p+1)/(t+1) -(double)p/t;
        };
        priority_queue<pair<double,pair<int,int>>>pq;;
        for(auto &l:classes)
        {
            pq.push({gain(l[0],l[1]),{l[0],l[1]}});
        }
        double ans;
        while(extraStudents--)
        {
            auto [g,pt]=pq.top();
            pq.pop();
            int p=pt.first,t=pt.second;
            pq.push({gain(p+1,t+1),{p+1,t+1}});
        }
        double sum=0;
          while (!pq.empty()) {
            auto [g, pt] = pq.top();
            pq.pop();
            sum += (double)pt.first / pt.second;
        }

        return sum / classes.size();
    }
};