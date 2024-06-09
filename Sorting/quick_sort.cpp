#include <iostream>
#include <ctime>
#include "swap.h"
#include "swap.cpp"
using namespace std;
// TODO 偶尔越界导致无输出
int random(int minum, int maxum)
{
    srand((int)time(0));
    return minum + rand()%(maxum-minum+1);
}

int * quick_sort(int (&arr)[], int begin, int end)
{
    // int temp[end-begin+1];
    // int * p1 = temp;
    // int * p2 = p1 + (end-begin-1);
    int * part = new int[2];
    part[0] = begin-1;
    part[1] = end;
    int index = begin;
    while(index < part[1])
    {
        if(arr[index] > arr[end])
        {
            part[1]--;
            swap(&arr[index], &arr[part[1]]);
            // index++;
        }
        else if(arr[index] < arr[end])
        {
            part[0]++;
            swap(&arr[index], &arr[part[0]]);
            index++;
        }
        else
        {
            index++;
        }
    }
    swap(&arr[part[1]], &arr[end]);
    // for(int j = 0; j < end-begin; j++)
    // {
    //     arr[begin+j] = temp[j];
    // }
    return part; 
}

void process(int (&arr)[], int begin, int end)
{
    if(begin+1 >= end)
    {
        return;
    }
    int divi_index = random(begin, end);
    swap(&arr[divi_index], &arr[end]);
    int *part = quick_sort(arr, begin, end);
    process(arr, begin, part[0]);
    process(arr, part[1], end);
    delete[] part;
}

int main()
{
    int arr[]={2,1,3,1,10,4,8,9,1,4,4,6,5,7};
    int size = sizeof(arr) / sizeof(arr[0]);
    process(arr, 0, 13);
    for(int i=0; i<size; i++)
    {
        cout << *(arr+i) << "   i="<< i << endl;
    }
}