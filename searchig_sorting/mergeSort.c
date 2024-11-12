#include <stdio.h>
#include <stdbool.h>

void merge (int arr[], int low, int mid, int high) {

    int left = low;
    int right = mid + 1;

    int temp [high - low  + 1];
    int k = 0;

    while (left <= mid && right <= high) {
        if (arr[left] >= arr[right]) {
            temp[k] = arr[right];
            right++;
            k++; 
        }
        else {
            temp[k] = arr[left];
            left++;
            k++;
        }
    }

    while (left <= mid) {
        temp[k] = arr[left];
            left++;
            k++; 
    }

    while (right <= high) {
        temp[k] = arr[right];
            right++;
            k++; 
    }


    for (int i = 0; i < high - low + 1; i++) {
        arr[low + i] = temp[i];
    }

}

void mergeSort (int arr [],int low , int high) {

    if (low >= high) 
        return;

    int mid = (low + high) / 2;

    mergeSort (arr, low, mid);

    mergeSort (arr, mid + 1, high);

    merge (arr,low, mid, high);
}

int main () {

    int arr[] = {8,7,6,5,4,3,2,1};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++) {
        printf(" %d ", arr[i]);
    }

    int low = 0;
    int high = size - 1;

    mergeSort (arr,low,high);

    printf("\n\n");

    for (int i = 0; i < size; i++) {
        printf(" %d ", arr[i]);
    }


}