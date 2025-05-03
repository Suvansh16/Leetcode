class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        // Create frequency arrays to store counts for numbers 1 through 6 (index 1 to 6)
        // Each pair holds (total count, rotation count)
        vector<pair<int,int>> top_array(7);     // top_array[i] = {total count of i on top or bottom, rotations to get i on top}
        vector<pair<int,int>> bottom_array(7);  // bottom_array[i] = {total count of i on top or bottom, rotations to get i on bottom}
        
        // Initialize all entries to {0, 0}
        for(int i = 0; i < 7; i++) {
            top_array[i] = {0, 0};
            bottom_array[i] = {0, 0};
        }

        // Count occurrences and possible rotations
        for(int i = 0; i < tops.size(); i++) {
            int a = tops[i];
            int b = bottoms[i];

            if (a == b) {
                // No rotation needed, both sides have the same number
                top_array[a].first++;
                bottom_array[a].first++;
            } else {
                // Update total and rotation counts
                top_array[a].first++;           // a appears on top
                top_array[b].first++;           // b appears on bottom
                top_array[b].second++;          // need to rotate a to b for top

                bottom_array[a].first++;        // a appears on top
                bottom_array[b].first++;        // b appears on bottom
                bottom_array[a].second++;       // need to rotate b to a for bottom
            }
        }

        // Debug output: print top_array and bottom_array states
        for(int i = 0; i < 7; i++) {
            cout << top_array[i].first << " " << top_array[i].second << " ";
            cout << bottom_array[i].first << " " << bottom_array[i].second << " ";
            cout << endl;
        }

        int mini = INT_MAX;

        // Check which number (from 1 to 6) can be aligned across all dominoes
        for(int i = 1; i < 7; i++) {
            if (top_array[i].first == tops.size()) {
                // Number 'i' appears in all dominoes (either in top or bottom)
                // Choose the minimum rotations needed (either to top or bottom)
                mini = min({mini, top_array[i].second, bottom_array[i].second});
            }
        }

        // If no such number exists, return -1
        return mini == INT_MAX ? -1 : mini;
    }
};
