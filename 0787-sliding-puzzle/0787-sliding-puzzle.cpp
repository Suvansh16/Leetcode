class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start="";
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                start+=to_string(board[i][j]);
            }
        }
        string target="123450";
        unordered_set<string>st;
        st.insert(start);
        queue<string>q;
        q.push(start);
        unordered_map<int,vector<int>>map;
        map[0]={1,3};
        map[1]={0,2,4};
        map[2]={1,5};
        map[3]={0,4};
        map[4]={1,3,5};
        map[5]={2,4};
        int level=0;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                string top=q.front();
                q.pop();
                if(top==target)
                return level;
                int find_zero=top.find('0');
                for(auto i:map[find_zero])
                {
                    string new_string=top;
                    swap(new_string[i],new_string[find_zero]);
                    if(st.find(new_string)==st.end()){
                    q.push(new_string);
                    st.insert(new_string);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};