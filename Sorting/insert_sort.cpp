#include<iostream>
#include "swap.h"
#include "swap.cpp"
using namespace std;

int main()
{
    int arr[]={2,1,3,1,10,4,8,9,1,4,4,6,5,7};
    int len = sizeof(arr) / sizeof(arr[0]);
    for(int i=1; i<len; i++)
    {
        for(int j=i; j>0; j--)
        {
            if(arr[j-1]>arr[j])
            {
                swap(&arr[j], &arr[j-1]);
            }
            else break;
        }
    }
    for(int i=0; i<len; i++)
    {
        cout << *(arr+i) << "   i="<< i << endl;
    }
}