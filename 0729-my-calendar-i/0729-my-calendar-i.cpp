class MyCalendar {
public:
map<int,int>map;
    MyCalendar() {}
    bool book(int start, int end) {
        map[start]++;
        map[end]--;
        int sum=0;
        for(auto i:map){
            sum+=i.second;
            if(sum>1)
            {
                map[start]--;
                map[end]++;
                return false;
            }
        }
        return true;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */