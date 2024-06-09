#include <iostream>
#include "swap.h"
#include "swap.cpp"
using namespace std;


int main()
{
    int arr[]={2,1,3,1,10,4,8,9,1,4,4,6,5,7};
    int len = sizeof(arr) / sizeof(arr[0]);
    // select_sorting(arr, len);
    for(int i=0; i < len; i++)
    {
        for(int j=0; j < len-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
        cout << arr[i] <<endl;
    }

    system("pause");
}