#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int>& nums){
        // 中心索引
        int left_sum = 0;
        int total = accumulate(nums.begin(), nums.end(), 0);
        for(int i = 0; i < nums.size(); i++){
            if(left_sum == total - left_sum - nums[i])
                return i;
            left_sum += nums[i];
        }
        return -1;
    }

    int searchInsert(vector<int>& nums, int n){
        //给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
        // for(int i = 0; i < nums.size(); i++){
        //     if(nums[i] == n)
        //         return i;
        //     else if(nums[i] > n){
        //         nums.insert(nums.begin() + i, n);
        //         return i;
        //     }
        //     else continue;
        // }
        // nums.push_back(n);
        // return nums.size()-1;

        int left = 0, right = nums.size()-1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] == n)
                return mid;
            else if(nums[mid] < n)
                left = mid+1;
            if(nums[mid] > n)
                right = mid-1;
        }
        return left;
        
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        int slow=0, quick=0, sum = 0, ans = nums.size();

        for(; quick < nums.size(); quick++) {

            sum += nums[quick];
            if(sum >= target) {
                while(1) {
                    sum -= nums[slow++];
                    if(sum < target) break;
                }
                
                if(ans > (quick - slow + 1)) {ans = (quick - slow + 1);
                }
            }
        }
        if(ans == nums.size()) return 0;
        return ans;
        
    }
    
};


int main(){
    // 创建
    // vector<int> ivec(10, 1);
    vector<string> svec{"Hi,", "What's", "up?"};
    vector<int> v({2,3,1,2,4,3});
    //添加
    // ivec.push_back(2);

    //索引
    // cout << svec.size() << endl;
    // for(int i=0; i < svec.size(); i++){
    //     cout << svec[i] << " ";
    // }
    // cout << endl;
    // vector<int> tvec;
    // int num;
    // while(cin >> num){
    //     tvec.push_back(num);
    // }
    Solution s0;
    // cout << s0.pivotIndex(tvec) <<endl;
    // cout << s0.searchInsert(tvec, 2) <<endl;

    cout << s0.minSubArrayLen(7, v);


}