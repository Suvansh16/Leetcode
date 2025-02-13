#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        int count = 0;

        // Push all elements into the min heap
        for (int a : nums)
            pq.push(a);

        // If the smallest element is already >= k, return 0
        if (pq.top() >= k) return 0;

        // Continue while the smallest element is < k and we have at least two elements
        while (pq.size() > 1 && pq.top() < k) {
            long long l = pq.top(); pq.pop();
            long long m = pq.top(); pq.pop();

            long long newVal = l * 2 + m;
            pq.push(newVal);
            count++;
        }

        // If the final smallest element is still < k, return -1 (not possible to reach k)
        return pq.top() >= k ? count : -1;
    }
};
