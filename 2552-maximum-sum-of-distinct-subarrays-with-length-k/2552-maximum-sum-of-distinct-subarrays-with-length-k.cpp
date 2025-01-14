

class Solution {
public:
    

    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0;
        unordered_map<int, int> map;
        int n = nums.size();
        
        // Edge case: if nums has fewer than k elements, return 0
        if (n < k) return 0;

        // Initialize the map for the first window
        for (int i = 0; i < k; i++) {
            map[nums[i]]++;
        }
         long long temp = 0; 
        for(int i=0;i<k;i++)
        {
            temp+=nums[i];
        }
       
        int i = 0, j = k - 1;
        
        // Iterate through the array using the sliding window
        while (j < n) {
            // If the map size is exactly k, calculate the sum of keys
            if (map.size() == k) {
                sum = max(sum, temp);
            }

            // Slide the window
            // Remove the element nums[i] from the window
            map[nums[i]]--;
            temp -= nums[i];
            if (map[nums[i]] == 0) {
                map.erase(nums[i]); // Remove the element if its count becomes 0
            }

            // Move the window forward
            i++;
            j++;

            if (j < n) {
                // Add the next element nums[j] to the window
                map[nums[j]]++;
                temp += nums[j];
                cout<<temp<<endl;
            }
        }

        return sum;
    }
};

