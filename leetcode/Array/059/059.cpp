#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    //题目：生成螺旋矩阵
        vector<vector<int>> generateMatrix(int n) {
            vector<vector<int>> res(n, vector<int>(n, 0));
            //定义左闭右开的边界
            int start_i = 0, start_j = 0, offset = 1, loop = n/2;
            int count = 1;
            int i, j;
            while(loop--) {
                // 上边
                int j = start_j, i = start_i;
                for(; j < (n - offset); j++) { //左闭右开,每次遍历都是最后一个不处理
                    res[i][j] = count++;
                }
                // 右边
                for(i; i < (n - offset); i++) {
                    res[i][n - offset] = count++;
                }
                // 下边
                for(; j > start_j; j--) {
                    res[n - offset][j] = count++;
                }
                // 左边
                for(; i > start_i; i--) {
                    res[i][start_j] = count++;
                }

                start_i++;
                start_j++;
                offset++;
            }
            // 处理剩余的中心点的情况
            if(n % 2) {
                res[n/2][n/2] = count;
            }
            return res;
        }
};

int main() {
    Solution2 s;
    int n = 6;
    vector<vector<int>> res = s.generateMatrix(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << res[i][j] << "-";
            cout << &res[i][j] << " "; // vector的地址同行连续 同列有余量
        }
        cout << endl;
    }
}