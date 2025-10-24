/*
Problem Statement : K Closest Points to Origin
Explanation : You are given an array of coordinate pairs, and you need to find
k points from that array that are closest to the origin (0,0).
Identification : Heap -> closest (use max heap)
Time Complexity : O(n log k)
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    int n = points.size();

    // Step 1: Create a max heap
    priority_queue<pair<int, pair<int, int>>> maxH;

    // Step 2: Traverse through each point
    for (int i = 0; i < n; i++) {
        int x = points[i][0];
        int y = points[i][1];
        int dist = x * x + y * y; // distance from origin (no sqrt needed)

        maxH.push({dist, {x, y}}); // push into heap

        if (maxH.size() > k) {
            maxH.pop(); // remove the farthest point
        }
    }

    // Step 3: Extract k closest points
    vector<vector<int>> result;
    while (!maxH.empty()) {
        pair<int, int> p = maxH.top().second;
        result.push_back({p.first, p.second});
        maxH.pop();
    }

    reverse(result.begin(), result.end()); // optional (to show from closest to farthest)

    return result;
}

int main() {
    vector<vector<int>> points = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
    int k = 2;

    vector<vector<int>> result = kClosest(points, k);

    for (auto p : result) {
        cout << "(" << p[0] << ", " << p[1] << ")" << endl;
    }

    return 0;
}
