#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cuts(string s) {
        if (s[0] == '0') return -1;
        int n = s.size();

        unordered_set<long long> powers;
        for (long long p = 1; p <= 1000000000LL; p *= 5)
            powers.insert(p);

        vector<int> dp(n + 1, n + 1);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') continue;
            long long num = 0;
            for (int j = i; j < n && num <= 1000000000LL; ++j) {
                num = (num << 1) + (s[j] - '0'); // build number in binary
                if (powers.count(num) && dp[j + 1] <= n) {
                    dp[i] = min(dp[i], 1 + dp[j + 1]);
                }
            }
        }

        return dp[0] > n ? -1 : dp[0];
    }
};
