class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int>result;
        for(int i=0;i<expression.length();i++)
        {
            if(expression[i]=='+' || expression[i]=='-' || expression[i]=='*')
            {
                vector<int>left=diffWaysToCompute(expression.substr(0,i));
                vector<int>right=diffWaysToCompute(expression.substr(i+1));
                for(int x:left)
                {
                    for(int y:right)
                    {
                        if(expression[i]=='+')
                        result.push_back(x+y);
                        else if(expression[i]=='-')
                        result.push_back(x-y);
                        else
                        result.push_back(x*y);
                    }
                }

            }
           
        }
        if(result.empty())
        result.push_back(stoi(expression));
        return result;
    }
};