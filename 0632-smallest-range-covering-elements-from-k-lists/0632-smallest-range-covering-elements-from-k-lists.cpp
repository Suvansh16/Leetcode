class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k=nums.size();

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
       //{ pq store three things element,list number ,index in list}
        vector<int>range={-100000,100000};
        int max_ele=INT_MIN;

        for(int i=0;i<k;i++)
        {
            pq.push({nums[i][0],i,0});
            max_ele=max(max_ele,nums[i][0]);

        }
        while(!pq.empty()){
            vector<int>top=pq.top();
            pq.pop();
            int min_ele=top[0];
            int list=top[1];
            int list_idx=top[2];

            if((max_ele-min_ele)<(range[1]-range[0]))
            {
                range={min_ele,max_ele};
            }

            if(list_idx+1<nums[list].size())
            {
                pq.push({nums[list][list_idx+1],list,list_idx+1});
                max_ele=max(max_ele,nums[list][list_idx+1]);
            }
            else
            break;

        }

        return range;
    }
};