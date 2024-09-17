class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int>ans;
        for(int i=0;i<timePoints.size();i++)
        {
            string a=timePoints[i];
            int hour=stoi(a.substr(0,2));
            int min=stoi(a.substr(3));
            int c=hour*60+min;
            ans.push_back(c);
        }
        sort(ans.begin(),ans.end());
        int result=INT_MAX;
        for(int i=1;i<ans.size();i++)
        {
            result=min(result,ans[i]-ans[i-1]);
        }
        return min(result,(24*60-ans[ans.size()-1]+ans[0]));
    }
};