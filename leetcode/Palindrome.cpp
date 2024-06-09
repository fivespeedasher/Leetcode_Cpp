#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        //方法二 反转一半
        //类型转换成字符串
        string x_1 = std::to_string(x);
        auto mid_p = x_1.begin() + (x_1.end() - x_1.begin())/2;
        
        //翻转
        std::reverse(x_1.begin(), mid_p);
        
        //取到偶数的右中间，或者奇数的中间+1
        int mid = (x_1.length()+1) / 2;
        cout << "前半段：" << x_1.substr(0, mid) << " 后半段：" << x_1.substr(mid, string::npos) << '\t';
        return x_1.substr(0, mid)==x_1.substr(mid, string::npos);

    }
};
int main() {
    Solution s1;
    cout << boolalpha << s1.isPalindrome(11) << endl;
    cout << boolalpha << s1.isPalindrome(121);
}