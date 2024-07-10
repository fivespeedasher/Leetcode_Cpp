#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        long sum;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int ele = nums.size();
        for(int k=0; k < ele-3; k++) {
            if(nums[k] > target && target > 0) break;
            // k去重
            if(k > 0 && nums[k] == nums[k-1]) continue;
            // 三数之和
            for(int i=k+1; i < ele-2; i++) {
                // 二级剪枝
                if(nums[k] + nums[i] > target && target > 0) break;
                // i去重
                if(i > k+1 && nums[i] == nums[i-1]) continue;
                // 双指针
                int left = i+1, right = ele-1;
                while(left < right) {
                    long long sum = (long) nums[k] + nums[i] + nums[left] + nums[right];;
                    if(sum < target) left++;
                    else if(sum > target) right--;
                    else {
                        res.push_back({nums[k], nums[i], nums[left], nums[right]});
                        left++;
                        right--;
                        // 去重
                        while(left < right && nums[left] == nums[left-1]) left++;
                        while(left < right && nums[right] == nums[right+1]) right--;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums = {0,1};
    int target = 0;
    Solution s;
    vector<vector<int>> res = s.fourSum(nums, target);
    for(auto i : res) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}