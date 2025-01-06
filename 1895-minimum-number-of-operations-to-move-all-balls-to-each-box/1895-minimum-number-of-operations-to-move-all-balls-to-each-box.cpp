class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>left_balls;
        vector<int>right_balls;
        int n=boxes.length();
        
        for(int i=0;i<n;i++)
        {
            if(i==0)
            left_balls.push_back(0);
            else
            {
                int sum=0;
                for(int j=0;j<i;j++)
                {
                    if(boxes[j]=='1')
                    {
                        sum+=abs(j-i);
                    }
                }
                left_balls.push_back(sum);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i==n-1)
            right_balls.push_back(0);
            else
            {
                int sum=0;
                for(int j=i+1;j<n;j++)
                {
                    if(boxes[j]=='1')
                    {
                         sum+=abs(j-i);
                    }
                }
                right_balls.push_back(sum);
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            ans.push_back(left_balls[i]+right_balls[i]);
        }
        return ans;

    }
};