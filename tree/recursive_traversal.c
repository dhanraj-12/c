#include <stdio.h>
#include <stdlib.h>
// Definition of a TreeNode
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
// Function to create a new tree node
struct TreeNode *createNode(int key)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct
                                                                TreeNode));
    newNode->val = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// Function to insert a new key in the binary tree
struct TreeNode *insert(struct TreeNode *root, int key)
{
    if (root == NULL)
    {
        return createNode(key);
    }
    // Insert in level order
    if (root->left == NULL)
    {
        root->left = insert(root->left, key);
    }
    else if (root->right == NULL)
    {
        root->right = insert(root->right, key);
    }
    else
    {
        root->left = insert(root->left, key);
    }
    return root;
}
// Inorder traversal (left-root-right)
void inorder(struct TreeNode *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}
// Preorder traversal (root-left-right)
void preorder(struct TreeNode *root)
{
    if (root != NULL)
    {
        printf("%d ", root->val);
        preorder(root->left);
        preorder(root->right);
    }
}
// Postorder traversal (left-right-root)
void postorder(struct TreeNode *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->val);
    }
}
// Main function for demonstration
int main()
{
    struct TreeNode *root = NULL;
    int choice, key;
    do
    {
        printf("\nMenu:\n");
        printf("1. Insert a node\n");
        printf("2. Inorder Traversal\n");
        printf("3. Preorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            root = insert(root, key);
            break;
        case 2:
            printf("Inorder Traversal:\n");
            inorder(root);
            printf("\n");
            break;
        case 3:
            printf("Preorder Traversal:\n");
            preorder(root);
            printf("\n");
            break;
        case 4:
            printf("Postorder Traversal:\n");
            postorder(root);
            printf("\n");
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}