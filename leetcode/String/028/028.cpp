#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int count = 0;
        if(needle.size() == 0) return 0;
        if(needle.size() > haystack.size()) return -1;
        for(int i=0; i < haystack.size()-needle.size()+1; i++) {
            if(haystack[i] == needle[0]){
                count++;
                for(int j=1,k=i+1; j < needle.size(); j++,k++) {
                    if(haystack[k] == needle[j]) {
                        count++;
                    }
                    else {
                        count = 0;
                        break;
                    }
                }
                if(count == needle.size()) return i;
            }
        }
        return -1;
    } 
};

int main() {
    Solution s;
    string haystack = "a";
    string needle = "a";
    cout << s.strStr(haystack, needle) << endl;
}