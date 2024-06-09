#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
    public:
        vector<int> sortedSquares(vector<int>& nums) {
            // 题目：有序数组的平方排序
            // 双指针头尾遍历
            int head = 0;
            int tail = nums.size()-1;
            vector<int> res(nums.size());
            int index = nums.size()-1;
            for(;head <= tail;) { // 左闭右闭，等于时区间有意义
                if(abs(nums[head]) > abs(nums[tail])) {
                    res[index] = pow(nums[head],2);
                    head ++;
                    index --;
                }
                else {
                    res[index] = pow(nums[tail],2);
                    tail --;
                    index --;
                }
            }
            return res;
        }
};

int main() {
    Solution s;
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> res = s.sortedSquares(nums);
    for(auto i:res) {
        cout << i << " ";
    }
    return 0;
}