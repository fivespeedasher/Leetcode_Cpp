#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int res = 0;
        unordered_map<int, int> m;
        for(int i: nums1) {
            for(int j: nums2) {
                m[i+j]++;
            }
        }
        for(int i: nums3) {
            for(int j: nums4) {
                if(m.count(-i-j)>0) {
                    res += m[-i-j];
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {-2, -1};
    vector<int> nums3 = {-1, 2};
    vector<int> nums4 = {0, 2};
    Solution s;
    cout << s.fourSumCount(nums1, nums2, nums3, nums4) << endl;
}