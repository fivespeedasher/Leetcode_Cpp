#include <iostream>
using namespace std;

void merge(int (&arr)[], int head, int tail)
{
    int mid = head + ((tail - head) >> 1);
    int p2 = mid+1;
    int p1 = head;
    int temp[tail-head+1];
    int i = 0;

    // int * mid = head + (tail-head) / 2;
    // int * p2 = mid;
    while( i <= tail - head)
    {
        if (p1 <= mid && p2 <= tail)
        {
            if(arr[p1] >= arr[p2])
            {
                temp[i] = arr[p2];
                p2++;
                i++; 
            }
            else
            {
                temp[i] = arr[p1];
                p1++;
                i++;
            }
        }
        else if (p1 > mid)
        {
            for(; p2 <= tail; p2++)
            {
                temp[i] = arr[p2];
                i++;
            }
        }
        else
        {
            for(; p1 <= mid; p1++)
            {
                temp[i] = arr[p1];
                i++;
            }
        }
    }
    for(i = head; i<=tail; i++)
    {
        arr[i] = temp[i-head]; 
    }
}

void process(int (&arr)[], int head, int tail)
{
    if(head >= tail)
    {
        return;
    }
    else
    {
        int mid = head + (tail-head)/2;
        process(arr, head, mid);
        process(arr, mid+1, tail);
        merge(arr, head, tail);
    }
}



int main()
{
    int arr[]={2,1,3,1,10,4,8,9,1,4,4,6,5,7};
    int size = sizeof(arr) / sizeof(arr[0]);
    process(arr, 0, size-1);
    // process(arr, 0, 3);
    for(int i=0; i<size; i++)
    {
        cout << *(arr+i) << "   i="<< i << endl;
    }
    system("pause");
}

