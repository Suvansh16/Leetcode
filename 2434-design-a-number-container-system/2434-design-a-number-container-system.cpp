class NumberContainers {
public:
unordered_map<int,set<int>>map;
unordered_map<int,int>indices_map;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(indices_map.find(index)!=indices_map.end())
        {
            int prev_number=indices_map[index];
            map[prev_number].erase(index);
            if(map[prev_number].empty())
            map.erase(prev_number);
        }
        indices_map[index]=number;
        map[number].insert(index);
    }
    
    int find(int number) {
        if(map.find(number)!=map.end())
        return *map[number].begin();
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */