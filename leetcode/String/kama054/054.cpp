#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string replaceNumber(string s) {
        int n = 0, soldIndex = s.size()-1;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] >= '0' && s[i] <= '9') {
                n++;
            }
        }
        s.resize(s.size() + 5*n, ' ');
        int j = s.size() - 1;
        for(;soldIndex >= 0; soldIndex--) {
            if(s[soldIndex] >= '0' && s[soldIndex] <= '9') {
                s[j--] = 'r';
                s[j--] = 'e';
                s[j--] = 'b';
                s[j--] = 'm';
                s[j--] = 'u';
                s[j--] = 'n';
            }
            else {
                s[j--] = s[soldIndex];
            }
        }
        return s;
    }
};

int main() {
    string s = "a1b2c3";
    Solution sol;
    s = sol.replaceNumber(s);
    cout << s << endl;
}