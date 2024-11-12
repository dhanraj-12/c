#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};

struct tree *create(int data)
{
    struct tree *newnode = (struct tree *)malloc(sizeof(struct tree));
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->data = data;
    return newnode;
}

void insert(struct tree *root, int data)
{
    struct tree *ptr = root;
    struct tree *prev = NULL;
    while (ptr)
    {
        prev = ptr;
        if (data == root->data)
        {
            return;
        }
        else if (data < ptr->data)
        {
            ptr = ptr->left;
        }
        else 
        {
            ptr = ptr->right;
        }
    }
    struct tree *new = create(data);
    if (prev->data < data)
    {
        prev->right = new;
    }
    else
    {
        prev->left = new;
    }
}
struct tree *Inorderpredecesor(struct tree *root)
{
    root = root->left;
    while (root && root->right)
    {
        root = root->right;
    }
    return root;
}
struct tree *delete(struct tree *root, int data)
{
    struct tree *ipre;
    if (root == NULL)
    {
        return NULL;
    }
    else if (root->data > data)
    {
        root->left = delete (root->left, data);
    }
    else if (root->data < data)
    {
        root->right = delete (root->right, data);
    }
    else
    {
        if (root->left == NULL)
        {
            struct tree *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct tree *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            ipre = Inorderpredecesor(root);
            root->data = ipre->data;
            root->left = delete (root->left, ipre->data);
        }
    }
    return root;
}

void Inorder(struct tree *root)
{
    if (root == NULL)
        return;
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}
int main()
{
    struct tree *root = NULL;
    int choice, data;
    while (1)
    {
        printf("\nBinary search tree operations : \n");
        printf("1.insert : \n");
        printf("2.delete : \n");
        printf("3.Inorder traverse : \n");
        printf("4.Exit: \n");
        printf("Enter the choice : \n");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
            printf("Enter the data to be inserted :");
            scanf("%d", &data);

            if (root == NULL)
            {
                root = create(data);
            }
            else
            {
                insert(root, data);
            }
            break;
        case 2:
            printf("Enter the value to be dalete : ");
            scanf("%d", &data);
            root = delete (root, data);
            printf("node is deleted succesfully !!");

            break;
        case 3:
            printf("Inorder traversal : ");
            Inorder(root);
            printf("\n");
            break;

        case 4:
            printf("exiting programe ...");
            exit(0);

        default:
            printf("Enter the valid choice...");
        }
    }
    return 0;
}