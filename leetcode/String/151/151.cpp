#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        removeExtraSpace(s);
        reverse(s, 0, s.size() - 1);
        // reverse each word
        int start = 0;
        for(int i = 0; i <= s.size(); i++) {// 左闭右开
            if(i == s.size() || s[i] == ' ') {
                reverse(s, start, i - 1);
                start = i + 1;
            }
        }
        return s;
    }

    void reverse(string& s, int begin, int end) {
        while(begin < end) {
            swap(s[begin++], s[end--]);
        }
    }
    void removeExtraSpace(string&s) {
        int fast = 0, slow = 0;
        bool need = false;
        for(; fast < s.size(); fast++) {
            if(s[fast] != ' ') {
                s[slow++] = s[fast];
                need = true;
            }
            else if(s[fast] == ' ' && need) {
                s[slow++] = ' ';
                need = false;
            }
        }
        if(s[slow - 1] == ' ') {
            s.resize(slow - 1);
        }
        else {
            s.resize(slow);
        }
    }
};

int main() {
    Solution s;
    string str = "  hello world!  ";
    cout << s.reverseWords(str) << endl;
}