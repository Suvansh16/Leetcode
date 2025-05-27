class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();

        priority_queue<int,vector<int>,greater<int>>past;

        priority_queue<int>max_heap;

        sort(queries.begin(),queries.end());

        int j=0;
        int count=0;
        for(int i=0;i<n;i++)
        {
            while(j<queries.size() && queries[j][0]==i)
            {
                max_heap.push(queries[j][1]);
                j++;
            }

            nums[i]-=past.size();

            while(nums[i]>0 && !max_heap.empty() && max_heap.top()>=i)
            {
                int r=max_heap.top();
                max_heap.pop();
                count++;
                past.push(r);
                nums[i]--;
            }
            if(nums[i]>0)
            return -1;
            while(!past.empty() && past.top()<=i)
            {
                past.pop();

            }

        }
        return queries.size()-count;
    }
};