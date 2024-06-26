#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
// 题目：取数组交集
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // 转set去重
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> res;

        // 去除掉s1的元素
        for(auto num : nums2) {
            if(s1.find(num) != s1.end()) { // num在s1中
                res.insert(num);
            }
        }
        return vector<int>(res.begin(), res.end()); //该构造函数提供临时对象，无需命名
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};
    vector<int> result = s.intersection(nums1, nums2);
    for(auto i : result) {
        cout << i << ' ';
    }
}