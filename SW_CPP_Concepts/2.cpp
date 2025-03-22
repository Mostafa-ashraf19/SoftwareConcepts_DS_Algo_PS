#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include <string>

using namespace std;

int mostBooked(int n, vector<vector<int>>& meetings) {

    // sort meetings based on start time.
    std::sort(meetings.begin(), meetings.end(), [](vector<int>& x, vector<int>& y){
       return x[0] < y[0];
    });
    // available rooms
    std::vector<int> available(n);
    iota(available.begin(), available.end(), 0);

    // unused rooms
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> used;
    // Count
    std::vector<int> count(n, 0);

    for (auto& meeting : meetings) {
        int start = meeting[0], end = meeting[1];
        
        // Free up rooms which are done before the start of the current meeting
        while (!used.empty() && used.top().first <= start) {
            available.push_back(used.top().second);
            used.pop();
        }

        if (!available.empty()) {
            // Use the lowest indexed available room
            int room = *min_element(available.begin(), available.end());
            available.erase(remove(available.begin(), available.end(), room), available.end());
            used.push({end, room});
            count[room]++;
        } else {
            // All rooms are occupied, delay the meeting until the earliest available room is free
            auto [free_time, room] = used.top();
            used.pop();
            used.push({free_time + (end - start), room});
            count[room]++;
        }
    }

    return std::distance(count.begin(), std::max_element(count.begin(), count.end()));
}


int main() {
    // Solution sol;
    vector<vector<int>> meetings = {{0,10},{1,5},{2,7},{3,4}};
    // {{0, 10}, {1, 5}, {2, 7}, {3, 4}, {5, 8}, {8, 10}};
    int n = 3;
    int mostBookedRoom = mostBooked(n, meetings);
    cout << "The room with the most meetings is: " << mostBookedRoom << endl;
    return 0;
}
