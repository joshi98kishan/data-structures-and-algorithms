#include <stdio.h>
#include<iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void insertion_sort(int arr[], int len){
    for(int i=1; i<len; i++){
        int key = arr[i];
        int j = i-1;

        while(j>=0 && key<arr[j]){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

void bubble_sort(int arr[], int len){
    for(int i=len-1; i>=1; i--){
        for(int j=0; j<i; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void selection_sort(int arr[], int len){
    for(int i=0; i<len-1; i++){
        int smallest = i;
        
        for(int j=i+1; j<len; j++){
            if(arr[j]<arr[smallest]){
                smallest = j;
            }
        }
        
        int temp = arr[smallest];
        arr[smallest] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int arr[] = {45, 12, 5, 1, 0, -99, -24};
    int len = 7;

    auto start = high_resolution_clock::now();

    // insertion_sort(arr, len);
    // bubble_sort(arr, len);
    selection_sort(arr, len);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop-start);


    cout<<"Time taken by sorting function "<<duration.count()<<endl<<endl;

    for(int i=0; i<len; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
