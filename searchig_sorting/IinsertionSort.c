#include <stdio.h>
#include <stdbool.h>

int main () {

    int arr[] = {5,7,8,1,4,2,3,6};
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < size; i++) {
        printf(" %d ", arr[i]);
    }


    for (int i = 1; i < size; i++) {

        int target = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > target) {

            arr[j + 1] = arr[j];
            arr[j] = target;
            j--;

        }

    }

    printf("\n\n");

    for (int i = 0; i < size; i++) {
        printf(" %d ", arr[i]);
    }


}