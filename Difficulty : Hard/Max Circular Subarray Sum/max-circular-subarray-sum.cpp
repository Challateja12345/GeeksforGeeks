#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kadane(const vector<int>& a) {
        int max_sum = a[0], curr_sum = a[0];
        for (int i = 1; i < a.size(); i++) {
            curr_sum = max(a[i], curr_sum + a[i]);
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum;
    }

    int maxCircularSum(vector<int>& arr) {
        int n = arr.size();
        
        // Standard Kadane’s result (max subarray sum without wrap-around)
        int max_kadane = kadane(arr);

        // Total sum of array
        int total_sum = accumulate(arr.begin(), arr.end(), 0);

        // Invert array for circular case
        for (int i = 0; i < n; i++) arr[i] = -arr[i];
        int max_circular = total_sum + kadane(arr);
        for (int i = 0; i < n; i++) arr[i] = -arr[i]; // restore

        // If all elements are negative, max_circular will be 0 → use max_kadane
        return (max_circular == 0) ? max_kadane : max(max_kadane, max_circular);
    }
};
