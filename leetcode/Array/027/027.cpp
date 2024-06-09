#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        int removeElement(vector<int>& nums,int val) {
            // 题目：删除数组中等于val的元素，返回删除后数组的长度
            // 快慢指针
            int slowIndex = 0;
            int fastIndex = 0;
            while(fastIndex < nums.size()) {
                if (nums[fastIndex] != val) {
                    nums[slowIndex] = nums[fastIndex];
                    fastIndex ++;
                    slowIndex ++; // 左开
                }
                else {
                    fastIndex ++;
                }
            }
            return slowIndex;
        }
};
int main() {
    Solution s;
    vector<int> nums = {5, 2, 3, 4, 5, 6, 7, 5, 9};
    cout << s.removeElement(nums,5) << endl;
    return 0;
}