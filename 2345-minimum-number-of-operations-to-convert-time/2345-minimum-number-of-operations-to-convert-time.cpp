class Solution {
public:
    int convertTime(string current, string correct) {
        int a=stoi(current.substr(0,2))*60;
        int b=stoi(current.substr(3,2))+a;
        int c=stoi(correct.substr(0,2))*60;
        int d=stoi(correct.substr(3,2))+c;
        cout<<b<<" "<<d;
        int r=0;
        while(b<d)
        {
            if(d-b>=60)
            {
                b+=60;
            }
            else if(d-b>=15)
            b+=15;
            else if(d-b>=5)
            b+=5;
            else
            b+=1;
            r++;
        }
        return r;
    }
};