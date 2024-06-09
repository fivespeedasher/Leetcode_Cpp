#include <iostream>
using namespace std;

int max_digit(int arr[], int n){
    int d = 1;
    int p =10;
    for(int i = 0; i<n; i++){
        while (arr[i] > p)
        {
            p *= 10;
            d++;
        }
    }
    return d;
}

void radixsort(int arr[], int n){
    //找最大位数
    int d = max_digit(arr, n);
    int p = 1;
    int count[10] = {0};
    int help[n];
    for(int i = 1; i <= d; i++){
        //求count
        for(int j = 0; j < n; j++){
            count[arr[j] / p % 10]++;
        }
        for(int j = 1; j < 10; j++){
            count[j] += count[j-1];
        }

        //求help
        for(int j = n-1; j >= 0; j--){
            help[--count[arr[j] / p % 10]] = arr[j];
        }

        for(int j = 0; j < 10; j++){
            count[j] = 0;
        }

        for(int j = 0; j < n; j++){
            arr[j] = help[j];
        }

        p *= 10;
    }
}

int main(){
    int arr[]={2,1,3,1,10,4,8,9,1,4,4,6,5,7,20};
    int len = sizeof(arr) / sizeof(arr[0]);
    radixsort(arr, len);
    for(int i=0; i < len; i++)
    {
        cout << arr[i] <<endl;
    }
}