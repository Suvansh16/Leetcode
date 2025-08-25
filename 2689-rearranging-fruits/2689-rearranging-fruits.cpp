class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int> map1, map2;
        long long ans = 0;
        int mn = INT_MAX;

        for (int x : basket1) {
            map1[x]++;
            mn = min(mn, x);
        }
        for (int x : basket2) {
            map2[x]++;
            mn = min(mn, x);
        }

        unordered_map<int,int> diff1, diff2;
        for (auto it = map1.begin(); it != map1.end(); it++) {
            int k = it->first;
            int c1 = it->second;
            int c2 = map2.count(k) ? map2[k] : 0;
            if ((c1 + c2) % 2 != 0) return -1;
            if (c1 > c2) diff1[k] = (c1 - c2) / 2;
        }
        for (auto it = map2.begin(); it != map2.end(); it++) {
            int k = it->first;
            int c2 = it->second;
            int c1 = map1.count(k) ? map1[k] : 0;
            if ((c1 + c2) % 2 != 0) return -1;
            if (c2 > c1) diff2[k] = (c2 - c1) / 2;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq1;
        priority_queue<pair<int,int>> pq2;

        for (auto it = diff1.begin(); it != diff1.end(); it++) {
            pq1.push({it->first, it->second});
        }
        for (auto it = diff2.begin(); it != diff2.end(); it++) {
            pq2.push({it->first, it->second});
        }

        while (!pq1.empty() && !pq2.empty()) {
            pair<int,int> p1 = pq1.top(); pq1.pop();
            pair<int,int> p2 = pq2.top(); pq2.pop();

            int used = min(p1.second, p2.second);

            // \U0001f511 The fix: allow using global minimum element
          ans += 1LL * used * min(min(p1.first, p2.first), 2*mn);

            if (p1.second > used) pq1.push({p1.first, p1.second - used});
            if (p2.second > used) pq2.push({p2.first, p2.second - used});
        }

        return ans;
    }
};
