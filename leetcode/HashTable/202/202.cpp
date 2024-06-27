#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
// 题目：判断n是否为快乐数
    bool isHappy(int n) {
        unordered_map<int, int> count;
        int sum;
        while(n != 1) {
            sum = 0;
            while(n) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            n = sum;
            if(sum != 1 && ++count[sum] > 1) { //unordered_map int类型在首次访问时默认赋值0
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.isHappy(19) << endl;
}