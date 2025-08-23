#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    static int countNumbers(int n) {
        int c = 0;
        int lim = (int)sqrt(n);

        vector<int> spf(lim + 1, 0);  // Smallest prime factor
        for (int i = 2; i <= lim; i++) spf[i] = i;

        for (int i = 2; i * i <= lim; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= lim; j += i) {
                    if (spf[j] == j) spf[j] = i;
                }
            }
        }

        for (int i = 2; i <= lim; i++) {
            int p = spf[i];
            int q = spf[i / p];

            if (p * q == i && p != q && q != 1) {
                c++;
            } 
            else if (spf[i] == i) {
                long long val = 1;
                for (int k = 0; k < 8; k++) {
                    val *= i;
                    if (val > n) break;  // avoid overflow
                }
                if (val <= n) c++;
            }
        }
        return c;
    }
};
