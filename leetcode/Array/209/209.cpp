#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        //题目：查找大于等于s的长度最小的子数组
        // 暴力
        int minSubArrayLen1(int s, vector<int>& nums) {
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
        
        // 滑窗：关键在于只让末指针循环
        int minSubArrayLen2(int s, vector<int>& nums) {
            int left = 0, right = 0, sum = 0, min_len = nums.size() + 1;
            for(;right < nums.size(); right++) {
                sum += nums[right];
                while(sum - nums[left] >= s) {
                    sum -= nums[left];
                    left++;
                }
                if(sum >= s) min_len = min_len < (right - left + 1) ? min_len :  (right - left + 1);
            }
            return min_len == nums.size() + 1 ? 0 : min_len;
            // if(min_len < nums.size()-1) return min_len;
            // else return 0;
        }
    };

int main() {
    Solution s1;
   int s = 7;
    vector<int> nums = {2,3,1,2,4,3};
    int min_len = s1.minSubArrayLen2(s, nums);
    cout << min_len << endl;
};