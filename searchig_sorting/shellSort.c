#include <stdio.h>

int main () {
    int arr[] = {6,8,2,4,1,5,3,7};
    int size = sizeof(arr) / sizeof (arr[0]);

    for (int i = 0; i < size; i++) {
        printf(" %d ",arr[i]);
    }
    printf("\n");

    for (int gap = size / 2; gap >= 1; gap = gap/2) {
        for (int j = gap; j < size; j++) {
            for (int i = j - gap; i >= 0; i = i - gap) {
                if (arr[i] < arr[gap + i]) {
                    break;
                }
                else {
                    int temp = arr[i];
                    arr[i] = arr[gap + i];
                    arr[gap + i] = temp;
                }
            }
        }
    }

    for (int i = 0; i < size; i++) {
        printf(" %d ",arr[i]);
    }
    printf("\n");
}