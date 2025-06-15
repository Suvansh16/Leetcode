class Solution {
public:
int replacemin(int num, int y) {
    string t = to_string(num);
    int size = t.size();
    int digitpos = -1;

    if (size == 1)
        return 1;

    // Check if we can replace the first digit with 1
    if (t[0] - '0' != 1)
        digitpos = 0;

    // If not, find the first digit (after the first) that can be replaced with 0
    if (digitpos == -1) {
        for (int i = 1; i < size; i++) {
            if (t[i] - '0' != 0 && t[i]-'0'!=1) {
                digitpos = i;
                break;
            }
        }
    }

    if (digitpos == -1)
        return num;

    int digit = t[digitpos] - '0';
    char replac = (digitpos == 0) ? '1' : '0';

    string finalans;
    for (int i = 0; i < size; i++) {
        if (t[i] - '0' == digit)
            finalans.push_back(replac);
        else
            finalans.push_back(t[i]);
    }

    return stoi(finalans);
}

int replacemax(int num,int y)
{
    string t=to_string(num);
    int size=t.size();
    int digitpos=-1;
    for(int i=0;i<size;i++)
    {
        if(t[i]-'0'==9)
        continue;
        else
        {
            digitpos=i;
            break;
        }
    }
    if(digitpos==-1)
    return num;
    int digit=t[digitpos]-'0';
    string finalans;
    for(int i=0;i<size;i++)
    {
        if(t[i]-'0'==digit)
        finalans.push_back('9');
        else
        finalans.push_back(t[i]);
    }
    return stoi(finalans);
}
    int maxDiff(int num) {
      int  a=replacemax(num,9);
      cout<<a<<" ";
      int b=replacemin(num,0);
      return a-b;  
    }
};