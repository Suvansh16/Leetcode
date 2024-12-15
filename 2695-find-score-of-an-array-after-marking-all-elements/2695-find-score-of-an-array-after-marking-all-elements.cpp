class Solution {
public:
    typedef pair<int,int> p;
    long long findScore(vector<int>& nums) {
        long long ans=0;
        priority_queue<p,vector<p>,greater<p>>pq;
        int l=0;
        for(int &i:nums)
        {
            pq.push({i,l++});
        }
        vector<bool>marked(nums.size(),false);
        while(!pq.empty())
        {
            int a=pq.top().first;
            int b=pq.top().second;
            pq.pop();
            if(!marked[b])
            {
                ans+=a;
                if(b>0)
                marked[b-1]=true;
                if(b<(nums.size()-1))
                marked[b+1]=true;

            }

        }
        return ans;
    }
};