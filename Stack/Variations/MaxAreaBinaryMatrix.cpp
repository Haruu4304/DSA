#include <bits/stdc++.h>
using namespace std;

// Nearest Smaller to Left
vector<int> NSL(vector<int> &heights) {
    int n = heights.size();
    stack<pair<int, int>> s;
    vector<int> result;
    int pseudo = -1;

    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top().first >= heights[i])
            s.pop();

        if (s.empty()) result.push_back(pseudo);
        else result.push_back(s.top().second);

        s.push({heights[i], i});
    }

    return result;
}

// Nearest Smaller to Right
vector<int> NSR(vector<int> &heights) {
    int n = heights.size();
    stack<pair<int, int>> s;
    vector<int> result;
    int pseudo = n;

    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top().first >= heights[i])
            s.pop();

        if (s.empty()) result.push_back(pseudo);
        else result.push_back(s.top().second);

        s.push({heights[i], i});
    }

    reverse(result.begin(), result.end());
    return result;
}

// Maximum Area Histogram
int MAH(vector<int> &heights) {
    int n = heights.size();
    vector<int> left = NSL(heights);
    vector<int> right = NSR(heights);
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int width = right[i] - left[i] - 1;
        ans = max(ans, width * heights[i]);
    }

    return ans;
}

// Maximum Area Rectangle in Binary Matrix
int maximalRectangle(vector<vector<char>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> v(m, 0);
    int mx = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '0')
                v[j] = 0;
            else
                v[j] = v[j] + 1;
        }

        mx = max(mx, MAH(v));
    }

    return mx;
}

int main() {
    vector<vector<char>> matrix = {
        {'0','1','1','0'},
        {'1','1','1','1'},
        {'1','1','1','1'},
        {'1','1','0','0'}
    };

    cout << maximalRectangle(matrix);
}
