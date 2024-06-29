#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int> s(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if(s.count(target - nums[i])) {
                for(int j = i; j < nums.size(); j++) {
                    if(nums[j] == (target - nums[i]) && i != j) {
                        return {i, j};
                    }
                }
            }
        }
        return {};
    }
};

int main() {
    Solution s;
    vector<int> nums={2, 7, 11, 15};
    int target = 9;
    vector<int> res = s.twoSum(nums, target);
    cout << res[0] << " " << res[1] << endl;
}