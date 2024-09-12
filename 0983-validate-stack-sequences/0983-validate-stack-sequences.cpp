class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>s1;
        int i=0,j=0;
        while(true)
        {
            if(!s1.empty() && s1.top()==popped[i])
            {
                s1.pop();
                i++;
                if(i>=popped.size())
                return true;
            }
            else
            {
                if(j>=pushed.size())
                return false;
                s1.push(pushed[j]);
                j++;
            }
        }
        return false;
    }
};