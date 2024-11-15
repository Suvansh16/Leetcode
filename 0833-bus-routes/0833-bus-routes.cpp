#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0; // No need to take any bus if source == target
        
        unordered_map<int, vector<int>> stopToBuses; // Map each stop to the buses that go through it
        for (int i = 0; i < routes.size(); i++) {
            for (int stop : routes[i]) {
                stopToBuses[stop].push_back(i);
            }
        }

        // BFS initialization
        queue<int> q; // Queue of (current stop, number of buses taken so far)
        unordered_set<int> visitedStops; // Set of visited bus stops
        unordered_set<int> visitedBuses; // Set of visited buses to prevent reprocessing the same bus

        q.push(source);
        visitedStops.insert(source);
        int busesTaken = 0;

        // Perform BFS
        while (!q.empty()) {
            int qSize = q.size();
            busesTaken++; // We are now moving to the next level (next set of buses)

            for (int i = 0; i < qSize; i++) {
                int currentStop = q.front();
                q.pop();

                // If we reach the target, return the number of buses taken
                if (currentStop == target) return busesTaken - 1;

                // Explore all buses that go through this stop
                for (int bus : stopToBuses[currentStop]) {
                    if (visitedBuses.find(bus) != visitedBuses.end()) {
                        continue; // Skip already visited buses
                    }
                    visitedBuses.insert(bus);

                    // Explore all stops on this bus route
                    for (int stop : routes[bus]) {
                        if (visitedStops.find(stop) == visitedStops.end()) {
                            visitedStops.insert(stop);
                            q.push(stop);
                        }
                    }
                }
            }
        }

        // If we exhaust all possibilities without reaching the target, return -1
        return -1;
    }
};
