class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int>map;
        for(auto i:arr)
        {
            map[(i%k+k)%k]++;
           
        }
        if(map[0]%2!=0)
        return false;
        for(int i=1;i<=k/2;i++)
        {
            int a=i;
            int req=k-a;
            if(map[a]!=map[req])
            return false;
        }
        return true;
    }
};