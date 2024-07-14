#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0, r = s.size() - 1;
        while(l < r) {
            swap(s[l++], s[r--]);
        }
    }
};

int main() {
    vector <char> s = {'h', 'e', 'l', 'l', 'o'};
    Solution sol;
    sol.reverseString(s);
    for(auto c:s) {
        cout << c << " ";
    }
    return 0;
}