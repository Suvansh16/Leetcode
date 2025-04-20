class Solution {
public:
    int numRabbits(vector<int>& answers) {
        vector<int>arr(1001,0);
        int count=0;
        for(int i=0;i<answers.size();i++)
        {
            if(arr[answers[i]]==0)
            {
                count+=answers[i]+1;
                arr[answers[i]]=answers[i];
            }
            else
            {
                arr[answers[i]]--;
            }
        }
        return count;
    }
};