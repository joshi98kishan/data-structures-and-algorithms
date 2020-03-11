#include <stdio.h>
#include <iostream>
using namespace std;

void max_heapify(int arr[], int heap_size, int i){
    int largest = i;
    
    int left = 2*i+1;
    int right = 2*i+2;
    
    if( left < heap_size && arr[left] > arr[largest]){
        largest = left;
    }
    if( right < heap_size && arr[right] > arr[largest]){
        largest = right;
    }
    
    if(largest != i){
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        
        max_heapify(arr, heap_size, largest);
    }
}

void build_max_heap(int arr[], int heap_size){
    for(int i=(heap_size-1)/2; i>=0; i--){
        max_heapify(arr, heap_size, i);
    }
}

void heap_sort(int arr[], int heap_size){
    build_max_heap(arr, heap_size);
    
    int temp;
    
    for(int i=heap_size; i>=2; i--){
        max_heapify(arr, i, 0);
        
        temp = arr[i-1];
        arr[i-1] = arr[0];
        arr[0] = temp;
    }
}

int main()
{
    int arr[] = {7, 9, 3, 1, 16, 4, 2, 8, 14, 10};
    int heap_size = 10;
    
    heap_sort(arr, heap_size);

    for(int i=0; i<heap_size; i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
