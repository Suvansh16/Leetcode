class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>indegree(n+1,0);
        vector<int>outdegree(n+1,0);
        for(int i=0;i<trust.size();i++){
            int  a=trust[i][0];
            int b=trust[i][1];
            indegree[b]++;
            outdegree[a]++;
        }
        int ans=-1;
        for(int i=1;i<indegree.size();i++){
            if(indegree[i]==n-1 && outdegree[i]==0)
            ans=i;
        }
        return ans;
    }
};