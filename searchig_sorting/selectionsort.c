#include <stdio.h>
#include <stdbool.h>

int main () {

    int arr[] = {8,7,6,5,4,3,2,1};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++) {
        printf(" %d ", arr[i]);
    }


    for (int i = 0; i < size - 1; i++) {

        int mindex = i;

        for (int j = i + 1; j < size; j++) {
            if (arr[mindex] > arr[j]) {
                mindex = j;
            }   
        }

        int temp = arr[i];
        arr[i] = arr[mindex];
        arr[mindex] = temp;

    }

    printf("\n\n");

    for (int i = 0; i < size; i++) {
        printf(" %d ", arr[i]);
    }


}