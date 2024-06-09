#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        string out;
        for(int end = s.length()-1; end > 0; end--){
            if(s[end-1] == ' ')
                continue;
            int begin = end-1;
            while(begin > 0){
                if(s[begin-1] != ' ') {
                    begin--;
                }
                else break;
            }
            out.append(s.substr(begin, end-begin));
            out.append(" ");
            end = begin-1;
        }
        return out.substr(0, out.length()-1);
    }
};


int main(){
    // vector<string> strs(3);
    string s("the sky is blue");
    Solution sol;
    string ans = sol.reverseWords(s);
    // str_print(ans);
    cout << ans;
}