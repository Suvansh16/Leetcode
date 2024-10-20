class Solution {
public:
char solveopr(vector<char>&value,char opera)
{
    if(opera=='!')
    {
        return value[0]=='t'?'f':'t';

    }
    if(opera=='&')
    {
        for(char &ch:value)
        {
            if(ch=='f')
            return 'f';
        }
        return 't';
    }
    if(opera=='|')
     {
        for(char &ch:value)
        {
            if(ch=='t')
            return 't';
        }
        return 'f';
    }
    return 't';

}
    bool parseBoolExpr(string expression) {
      int n=expression.length();
      stack<char>s;
      for(int i=0;i<n;i++)
      {
        if(expression[i]==',')
        continue;
        if(expression[i]==')')
        {
            vector<char>value;
            while(s.top()!='(')
            {
                value.push_back(s.top());
                s.pop();

            }
            s.pop();
            char opera=s.top();
            s.pop();
            s.push(solveopr(value,opera));
        }
        else
        {
            s.push(expression[i]);
        }
      }
      return s.top()=='t'?true:false;
    }
};