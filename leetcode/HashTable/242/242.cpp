#include <iostream>
// #include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // 判长度
        if(s.size() != t.size()) {
            return false;
        }

        // 转为Hash表的Map类型
        int map[26] = {0};
        for(int i=0; i<s.size(); i++) {
            map[s[i] - 'a']++;
            map[t[i] - 'a']--;
        }
        // 判值是否全为零
        for(int i=0; i<26; i++) {
            if(map[i] != 0) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.isAnagram("anagram", "nagaram") << endl;
    cout << s.isAnagram("rat", "car") << endl;
    return 0;
}
