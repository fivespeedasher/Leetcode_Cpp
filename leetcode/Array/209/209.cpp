#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        //题目：查找大于等于s的长度最小的子数组
        int minSubArrayLen(int s, vector<int>& nums) {
            // 暴力
            int left = 0;
            int min_len = nums.size() + 1;
            int subLength, sum = 0;
            for(;left < nums.size();left ++){
                sum = 0;
                for(int right = left; right < nums.size(); right++) { //左闭右闭，right++是循环体后执行
                    sum += nums[right];
                    if(sum >= s) {
                        subLength = right - left + 1;
                        min_len = min_len < subLength ? min_len : subLength;
                        break;
                    }
                }
            }
            if(min_len == nums.size() + 1) return 0;
            else return  min_len;
            }
        };

int main() {
    Solution s1;
   int s = 7;
    vector<int> nums = {2,3,1,2,4,3};
    int min_len = s1.minSubArrayLen(s, nums);
    cout << min_len << endl;
}