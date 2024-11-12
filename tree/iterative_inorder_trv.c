#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
struct Node *insertNode(struct Node *root, int data)
{
    struct Node *node = newNode(data);
    if (root == NULL)
        return node;
    struct Node *queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front != rear)
    {
        struct Node *temp = queue[front++];
        if (temp->left == NULL)
        {
            temp->left = node;
            return root;
        }
        else
            queue[rear++] = temp->left;
        if (temp->right == NULL)
        {
            temp->right = node;
            return root;
        }
        else
            queue[rear++] = temp->right;
    }
    return root;
}
void inorderTraversal(struct Node *root)
{
    struct Node *stack[100];
    int top = -1;
    struct Node *current = root;
    while (current != NULL || top >= 0)
    {
        while (current != NULL)
        {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}
int main()
{
    struct Node *root = NULL;
    int n, data;
    printf("Enter the number of nodes in the binary tree: ");
    scanf("%d", &n);
    printf("Enter the values of the nodes: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        root = insertNode(root, data);
    }
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    return 0;
}
