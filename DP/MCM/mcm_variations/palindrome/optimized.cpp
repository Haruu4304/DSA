class Solution {
public:
    vector<vector<bool>> palindrome;
    vector<vector<int>> t;

    int solve(string &s, int i, int j) {
        if (i >= j) return 0;                    // empty or single char
        if (palindrome[i][j]) return 0;          // whole substring is palindrome
        if (t[i][j] != -1) return t[i][j];       // memoized

        int ans = INT_MAX;

        // Try every possible cut
        for (int k = i; k < j; k++) {
            if (palindrome[i][k]) { // only cut if left part is palindrome
                int temp = 1 + solve(s, k + 1, j);
                ans = min(ans, temp);
            }
        }
        return t[i][j] = ans;
    }

    int palPartition(string &s) {
        int n = s.length();
        palindrome.assign(n, vector<bool>(n, false));
        t.assign(n, vector<int>(n, -1));

        // Precompute palindrome table in O(n^2)
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (len == 1) palindrome[i][j] = true;
                else if (len == 2) palindrome[i][j] = (s[i] == s[j]);
                else palindrome[i][j] = (s[i] == s[j] && palindrome[i + 1][j - 1]);
            }
        }

        return solve(s, 0, n - 1);
    }
};