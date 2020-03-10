#include <stdio.h>
#include <iostream>
#include <chrono>
#include <limits>
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

void merge(int arr[], int p, int q, int r){
    int n1 = q-p+1;
    int n2 = r-q;
    
    int l1[n1+1];
    int l2[n2+1];
    
    for(int i=0; i<n1; i++){
        l1[i] = arr[p+i];
    }
    
    l1[n1] = numeric_limits<int>::max();
    
    for(int i=0; i<n2; i++){
        l2[i] = arr[q+1+i];
    }
    
    l2[n2] = numeric_limits<int>::max();
    
    int i=0, j=0;
    
    for(int k=p; k<=r; k++){
        if(l1[i] <= l2[j]){
            arr[k] = l1[i];
            i++;
        }else{
            arr[k] = l2[j];
            j++;
        }
    }
}

void merge_sort(int arr[], int p, int r){
    if(p<r){
        int q = (p+r)/2;
        merge_sort(arr, p, q);
        merge_sort(arr, q+1, r);
        merge(arr, p, q, r);
    }
}

int main()
{
    int arr[] = {45, 12, 5, 1, 0, -99, -24};
    int len = 7;

    auto start = high_resolution_clock::now();

    // insertion_sort(arr, len);
    // bubble_sort(arr, len);
    // selection_sort(arr, len);
    merge_sort(arr, 0, len-1);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop-start);


    cout<<"Time taken by sorting function "<<duration.count()<<endl<<endl;

    for(int i=0; i<len; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
