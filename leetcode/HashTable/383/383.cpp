#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canConstruct(string randomNote, string magzine) {
        unordered_map<char, int> m;
        for(char l: magzine) {
            m[l]++;
        }
        for(char l: randomNote) {
            m[l]--;
            if(m[l] < 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.canConstruct("aa", "aabc") << endl;
}