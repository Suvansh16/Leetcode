class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int n=meetings.size();
        int count=0;
        int a=meetings[0][0];
        count+=a-1;
        int b=meetings[0][1];
        for(int i=1;i<n;i++)
        {
            if(meetings[i][0]<=b){
                 b=max(meetings[i][1],b);
                 continue;
            }
           
            count+=(meetings[i][0]-b-1);
            b=max(meetings[i][1],b);
        }
        count+=(days-b);
        return count;
    }
};