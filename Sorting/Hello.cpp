#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
* An example
*/
int main()
{
    vector<string> msg {"Hello", "C++"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
    system("pause");
}