#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    void rotate(vector< vector<int> >& matrix){
        /* 旋转90°*/
        
        // 对角化
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j <i; j++){
                matrix[i][j] = matrix[i][j] ^ matrix[j][i];
                matrix[j][i] = matrix[i][j] ^ matrix[j][i];
                matrix[i][j] = matrix[i][j] ^ matrix[j][i];
            }
        }

        // 水平对称
        for(int i = 0; i < matrix.size(); i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }

    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        /*以对角线遍历的顺序，用一个数组返回m*m矩阵中的所有元素*/
        int n = mat.size()-1;
        vector<int> v, v_temp;
        for(int line = 0; line <= (n*2); line++){
            for(int i = line<n ? line:n; i >= 0; i--){
                if(line-i <= n)
                    v_temp.push_back(mat[i][line-i]);
            }
            if(line % 2 != 0)
                reverse(v_temp.begin(), v_temp.end());
            for(auto k:v_temp){
                v.push_back(k);
            }
            v_temp.clear();
            
        }
        return v;
    }
};

int main(){
    int row = 3, col = 3;
    vector<vector<int>> v1(row, vector<int>(col));
    for(int i = 0; i < row; i++){
        cout << "Input " << i << " row" << endl; 
        for(int j = 0; j < col; j++){
            cin >> v1[i][j];
        }
    }

    Solution s;

    // s.rotate(v1);
    // 打印二维数组
    // for(int i = 0; i < v1.size(); i++){
    //     for(int j = 0; j < v1[0].size(); j++){
    //         cout << v1[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    vector<int> v = s.findDiagonalOrder(v1);
    for(auto k:v){
        cout << k << " ";
    }

    // cout << endl << *v.end();
    

}