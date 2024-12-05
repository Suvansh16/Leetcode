class Solution {
public:
    bool canChange(string start, string target) {
        int n=start.length();
        int i=0;
        int j=0;
        while(i<n || j<n)
        {
            while(i<n && start[i]=='_')
            {
                i++;
            }
            while(j<n && target[j]=='_')
            {
                j++;
            }
             // If both i and j are out of bounds, we're done
            if (i == n && j == n) break;
            
            // If only one of them is out of bounds, return false
            if (i == n || j == n) return false;
            if(start[i]!=target[j])
            return false;
            if(start[i]=='L')
            {
                if(i<j)
                return false;
            }
            else if(start[i]=='R')
            {
                if(i>j)
                return false;
            }
            i++;
            j++;

        }
        return i==n && j==n;
    }
};