#include <stdio.h>
#define MAX 100

void reheapup(int heap[], int index)
{
    int parent = (index - 1) / 2;
    if (index > 0 && heap[index] > heap[parent])
    {
        int temp = heap[index];
        heap[index] = heap[parent];
        heap[parent] = temp;
        reheapup(heap, parent);
    }
}

void reheapdown(int heap[], int size, int index)
{
    int leftch = (2 * index) + 1;
    int rightch = (2 * index) + 2;
    int largest = index;
    if (leftch < size && heap[leftch] > heap[largest])
    {
        largest = leftch;
    }
    if (rightch < size && heap[rightch] > heap[largest])
    {
        largest = rightch;
    }
    if (largest != index)
    {
        int temp = heap[index];
        heap[index] = heap[largest];
        heap[largest] = temp;
        reheapdown(heap, size, largest);
    }
}

void buildheap(int heap[], int *size, int val)
{
    heap[*size] = val;
    (*size)++;
    reheapup(heap, (*size) - 1);
}

void printheap(int heap[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
}
int main()
{
    int heap[MAX];
    int size = 0;
    int choice, val, index;
    do
    {
        printf("\nMenu:\n");
        printf("1. Insert element (build heap)\n");
        printf("2. Reheap Up\n");
        printf("3. Reheap Down\n");
        printf("4. Print Heap\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the value to be insert in heap : ");
            scanf("%d", &val);
            buildheap(heap, &size, val);
            break;
        case 2:
            printf("Enter the index for reheapup the heap : ");
            scanf("%d", &index);
            if (index < size)
                reheapup(heap, index);
            else
                printf("Enter the valid index\n ");
            break;
        case 3:
            printf("Enter the index for reheapdown the heap : ");
            scanf("%d", &index);
            if (index < size)
                reheapdown(heap, size, index);
            else
                printf("Enter the valid index\n ");

            break;
        case 4:
            printf("Heap is : ");
            printheap(heap, size);
            break;
        default:
            printf("Enter valid choice ...");
        }
    } while (choice != 5);
    return 0;
}