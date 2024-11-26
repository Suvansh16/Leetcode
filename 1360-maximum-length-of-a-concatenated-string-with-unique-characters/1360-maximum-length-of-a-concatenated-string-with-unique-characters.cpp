class Solution {
public:
bool hasduplicate(string a, string b)
{
    unordered_set<char>st;
    for(char &ch:a)
    {
        st.insert(ch);
    }
     for(char &ch:b)
    {
        st.insert(ch);
    }
    return st.size()==(a.length()+b.length())?false:true;
}
int solve(vector<string>&arr,int i,string temp)
{
    if(i>=arr.size())
    return temp.length();
    int take=0;
    int nottake=0;
    if(hasduplicate(temp,arr[i]))
    {
        nottake=solve(arr,i+1,temp);
    }
    else
    {
        take=solve(arr,i+1,temp+arr[i]);
        //maanlo maximu current string me kuch aur add kara ke aana ho then
        nottake=solve(arr,i+1,temp);
    }
    return max(take,nottake);
}
    int maxLength(vector<string>& arr) {
        string temp="";
        int i=0;
        return solve(arr,i,temp);
    }
};