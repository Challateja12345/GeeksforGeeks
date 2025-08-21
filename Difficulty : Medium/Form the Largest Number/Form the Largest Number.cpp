class Solution {
public:
    string findLargest(vector<int>& arr) {
        vector<string> s;
        for (int x : arr) s.push_back(to_string(x));
        sort(s.begin(), s.end(), [](const string& x, const string& y) { 
            return x + y > y + x; 
        });
        if (s[0] == "0") return "0";
        string result;
        for (const string& str : s) result += str;
        return result;
    }
};
