class Solution {
public:
    int findPages(vector<int> &arr, int k) {
        if (k > arr.size()) return -1;
        int l = *max_element(arr.begin(), arr.end());
        int r = accumulate(arr.begin(), arr.end(), 0);
        while (l < r) {
            int m = l + (r - l) / 2;
            int s = 1, p = 0;
            for (int x : arr) {
                if (p + x > m) { s++; p = x; } 
                else p += x;
            }
            s <= k ? r = m : l = m + 1;
        }
        return l;
    }
};
