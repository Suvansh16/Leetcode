class Solution {
public:
    int maxJump(vector<int>& stones) {
        int ans=stones[1]-stones[0];

        //frog will move alternatively to get minimum diff 
        // we have to find two path and the two path will not intrract with each other
        
        for(int i=2;i<stones.size();i++)
        {
            ans=max(ans,stones[i]-stones[i-2]);
        }
        return ans;
    }
};