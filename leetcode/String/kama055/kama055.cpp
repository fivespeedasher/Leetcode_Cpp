#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string  rightRoateString(string s, int n) {
        int left = 0, right = s.size() - n;
        for(; right < s.size(); right++, left++) {
            swap(s[left], s[right]);
        }
        //后n个整体移到前面
        left = n;
        right = s.size() - n;
        for(; n > 0; n--) {
            insert(s, left++, right++);
        }
        return s;

    }
    void insert(string& s, int targetInd, int sourceInd) {
        while(sourceInd > targetInd) {
            swap(s[sourceInd], s[targetInd++]);
        }
    }

};

int main() {
    Solution s;
    string str = "abcdef";
    cout << s.rightRoateString(str, 2) << endl;
}