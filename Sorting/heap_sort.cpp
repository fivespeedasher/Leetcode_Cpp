#include <iostream>
#include "swap.h"
#include "swap.cpp"
using namespace std;

void heapify(int (&arr)[], int heap_size)
{
    int index = heap_size;
    int min_son;
    for(int i=0; i<=heap_size; i++){
        index = heap_size-i;
        if(2 * index + 2 <= heap_size){
            arr[2 * index + 1] < arr[2 * index + 2] ? min_son = (2 * index + 1) : min_son = (2 * index + 2);
        }
        else if(2 * index + 1 == heap_size){
            min_son = 2 * index + 1;
        }
        else{
            min_son = index;
        }
        if(arr[index] > arr[min_son]){
            swap(&arr[index], &arr[min_son]);
        }

        // while (2 * index + 1 <= heap_size){
        //     arr[index] = arr[2 * index + 1];
        //     swap(&arr[index], &arr[(index - 1) / 2]);
        //     index = (index - 1) / 2;
        // }
    }
    
}

int main()
{
    int arr[]={2,1,3,1,10,4,8,9,1,4,4,6,5,7,20};
    int len = sizeof(arr) / sizeof(arr[0]);
    int heap_size = len-1;
    while(heap_size >= 0){
        heapify(arr, heap_size);
        cout << arr[0] <<endl;
        swap(&arr[0], &arr[heap_size--]);
    }
}