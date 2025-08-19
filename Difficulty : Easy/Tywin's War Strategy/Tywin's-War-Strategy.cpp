#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minSoldiers(vector<int>& arr, int k) {
        int n = arr.size();
        int need = (n + 1) / 2;  // number of elements we need
        priority_queue<int, vector<int>, greater<int>> pq; // min-heap

        for (int x : arr) {
            int cost = (x % k == 0) ? 0 : (k - (x % k));
            pq.push(cost);
        }

        long long result = 0;
        for (int i = 0; i < need; i++) {
            result += pq.top();
            pq.pop();
        }
        return result;
    }
};
