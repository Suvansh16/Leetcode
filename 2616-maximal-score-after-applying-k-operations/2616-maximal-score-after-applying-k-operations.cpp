#include <queue>
#include <cmath>

class Solution {
public:
    long long maxKelements(std::vector<int>& nums, int k) {
        long long count = 0;
        std::priority_queue<int> pq(nums.begin(), nums.end()); // More concise initialization

        while (k--) {
            int a = pq.top();
            pq.pop();
            count += a;

            // Efficient integer division with ceiling effect
            int s = (a + 2) / 3;  // This is equivalent to ceil(a / 3.0) but works with integers
            pq.push(s);
        }

        return count;
    }
};
