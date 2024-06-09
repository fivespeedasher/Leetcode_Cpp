#include <iostream>
#include "swap.h"
#include "swap.cpp"

using namespace std;

// void select_sorting(int *p, int len);
// #define MAXLEN 20


// template <typename T>
// void select_sorting(int *p, int len)
// {
//     len = 2;
// }

int main()
{
    int arr[]={2,1,3,1,10,4,8,9,1,4,4,6,5,7};
    int len = sizeof(arr) / sizeof(arr[0]);
    // select_sorting(arr, len);
    for(int i=0; i < len; i++)
    {
        for(int j=i; j<len; j++)
        {
            if (arr[j] < arr[i])
            {
                {
                    swap(&arr[i], &arr[j]);
                } 
            }
        }
        cout << arr[i] <<endl;
    }

    system("pause");
}