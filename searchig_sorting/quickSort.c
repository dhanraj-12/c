#include <stdio.h>

int quick (int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high) {
            i++;
        }
        while (arr[j] > pivot && j >= low) {
            j--;
        }
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int part = quick (arr, low, high);
        quickSort (arr, low, part - 1);
        quickSort (arr, part + 1, high);
    }
}
int main () {

        int arr [] = {6,2,8,5,4,1,7,3};
        int size = sizeof(arr)/sizeof(arr[0]);
    
        for (int i = 0; i < size; i++) {
            printf(" %d ",arr[i]);
        }
        printf("\n");
    
        int low = 0;
        int high = size - 1;
        quickSort (arr, low, high);
    
        for (int i = 0; i < size; i++) {
            printf(" %d ",arr[i]);
        }
        printf("\n");
    
}