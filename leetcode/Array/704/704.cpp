#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search1(vector<int>& nums, int target) {
        //题目：二分查找
        // 左闭右闭
        int left = 0, right = nums.size()-1;
        while(left <= right) { // 考虑‘等于’是因为符合左闭右闭的假设: left==right有意义
            int mid = (left + right) >> 1;
            if (nums[mid] < target)
                {left = mid + 1;} // +1是符合左闭右闭的边界假设
            if (nums[mid] > target)
                {right = mid - 1;} // -1是符合左闭右闭的边界假设
            if (nums[mid] == target)
                {return mid;}
        }
        return -1;
    }

    int search2(vector<int>& nums, int target) {
        // 左闭右开
        int left = 0, right = nums.size(); // 注意这里左闭右开时的right
        while(left < right) { // 考虑‘等于’是因为符合左闭右开的假设，为了让区间合法。
            int mid = (left + right) >> 1;
            if (nums[mid] < target)
                {left = mid + 1;} // +1是符合左闭右闭的边界假设
            if (nums[mid] > target)
                {right = mid;}
            if (nums[mid] == target)
                {return mid;}
        }
        return -1;
    }
};

int main() {
    Solution s1,s2;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << s1.search1(nums,5) << endl;
    cout << s2.search2(nums,5) << endl;
    return 0;
}