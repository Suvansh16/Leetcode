class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string>ans;
        //starting with 1
        int t=1;
        for(int i=0;i<groups.size();i++)
        {
            if(groups[i]==t)
            {
                ans.push_back(words[i]);
                t=t==1?0:1;
            }
        }
        vector<string>ans2;
        t=0;
         for(int i=0;i<groups.size();i++)
        {
            if(groups[i]==t)
            {
                ans2.push_back(words[i]);
                t=t==1?0:1;
            }
        }
        return ans.size()>ans2.size()?ans:ans2;
    }
};