class Solution {
public:
char dfs(unordered_map<char,vector<char>>&map,char ch,vector<bool>&visited)
{
    visited[ch-'a']=true;
    char smallest=ch;
    
    for(char t:map[ch])
    {
       if(!visited[t-'a'])
       {
         char candi=dfs(map,t,visited);
         if(candi<smallest)
         smallest=candi;
       }
    }
   
    return smallest;
}
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char,vector<char>>map;
        for(int i=0;i<s2.length();i++)
        {
             

            map[s1[i]].push_back(s2[i]);
        
            map[s2[i]].push_back(s1[i]);
        }
        string result;
        vector<bool>visited(26,false);
        for (char ch:baseStr)
        {
                      fill(visited.begin(), visited.end(), false);

            result.push_back(dfs(map,ch,visited));
        }
        return result;
        
    }
};