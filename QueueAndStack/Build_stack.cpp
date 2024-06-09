#include <iostream>
#include <vector>
using namespace std;
class Mystack {
private:
    vector<int> data;
    int min;
public:
    MinStack() {
        int min = 99999;
    }
    void push(int x){
        data.push_back(x);
        min = x < min ? x:min;
    }

    bool is_empty(){
        if(data.size()==0) return true;
        else return false;
        // return data.empty();
    }
    
    int top(){
        return data.back();
    }
    
    void pop(){
        if(is_empty() == false){
            data.pop_back();
        }
    }
    
    int getMin() {
        return min;
    }
};

int main(){
    Mystack a;
    a.push(1);
    a.push(2);
    a.push(3);
    cout << a.top() << endl;
    a.pop();
    cout << a.top() << endl;
    return 0;
}