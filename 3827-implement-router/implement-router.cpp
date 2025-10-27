#include <bits/stdc++.h>
using namespace std;

class Router {
private:
    deque<vector<int>> routerMemory;                
    set<vector<int>> detectDuplicates;              
    unordered_map<int, vector<int>> destTimestamps;
    unordered_map<int, int> removedCount;  
    int size;

public:
    Router(int memoryLimit) {
        size = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        vector<int> packet = {source, destination, timestamp};

        if (detectDuplicates.find(packet) != detectDuplicates.end())
            return false;

        if ((int)routerMemory.size() == size) {
            vector<int> oldest = routerMemory.front();
            routerMemory.pop_front();
            detectDuplicates.erase(oldest);

            removedCount[oldest[1]]++;
        }

        routerMemory.push_back(packet);
        detectDuplicates.insert(packet);
        destTimestamps[destination].push_back(timestamp);

        return true;
    }
    
    vector<int> forwardPacket() {
        if (routerMemory.empty()) return {};

        vector<int> packet = routerMemory.front();
        routerMemory.pop_front();
        detectDuplicates.erase(packet);

        removedCount[packet[1]]++;

        return packet;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if (!destTimestamps.count(destination))
            return 0;

        vector<int> &v = destTimestamps[destination];
        int offset = removedCount[destination];
        if (offset >= (int)v.size()) return 0;

        auto beginIt = v.begin() + offset;
        auto it1 = lower_bound(beginIt, v.end(), startTime);
        auto it2 = upper_bound(beginIt, v.end(), endTime);

        return int(it2 - it1);
    }
};
