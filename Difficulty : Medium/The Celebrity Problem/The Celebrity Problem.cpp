class Solution {
public:
    int celebrity(vector<vector<int>>& m) {
        int n = m.size(), c = 0;
        for (int i = 1; i < n; i++) if (m[c][i]) c = i;
        for (int i = 0; i < n; i++) if (i != c && (m[c][i] || !m[i][c])) return -1;
        return c;
    }
};
