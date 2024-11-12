#include <stdio.h>
int sequentialSearch(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        int looker = arr[i];
        if (looker == target)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {3, 8, 2, 10, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;
    printf("Enter the number to search: ");
    scanf("%d", &target);
    int result = sequentialSearch(arr, n, target);
    if (result != -1)
    {
        printf("Element found at index %d\n", result);
    }
    else
    {
        printf("Element not found in the array\n");
    }
    return 0;
}