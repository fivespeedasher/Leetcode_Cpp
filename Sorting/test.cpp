#include <iostream>
#include <string>

using namespace std;

/*
* An example
*/
void turn_one(int data[], int n);

int main()
{
    int a = 5, b = 1, c=3;
    int x;
    x = (x = c<b ? c:b) < a ? x:a;
    cout << x;
}

void turn_one(int data[], int n){
    data[0] = 1;
}