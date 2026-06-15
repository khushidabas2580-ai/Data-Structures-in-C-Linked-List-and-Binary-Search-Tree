#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
/*--------------------------------------------------
Function: createNode
Time Complexity: O(1)
--------------------------------------------------*/
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
/*--------------------------------------------------
Function: insert
Average Time Complexity: O(log n)
Worst Case Time Complexity: O(n)
--------------------------------------------------*/
struct Node *insert(struct Node *root, int value)
{
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}
/*--------------------------------------------------
Function: search
Average Time Complexity: O(log n)
Worst Case Time Complexity: O(n)
--------------------------------------------------*/
struct Node *search(struct Node *root, int key)
{
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

/*--------------------------------------------------
Function: findMin
Time Complexity: O(log n)
Worst Case: O(n)
Returns node with minimum value
--------------------------------------------------*/
struct Node *findMin(struct Node *root)
{
    while (root && root->left != NULL)
        root = root->left;
    return root;
}
/*--------------------------------------------------
Function: findMax
Time Complexity: O(log n)
Worst Case: O(n)
Returns node with maximum value
--------------------------------------------------*/
struct Node *findMax(struct Node *root)
{
    while (root && root->right != NULL)
        root = root->right;
    return root;
}
/*--------------------------------------------------
Function: deleteNode
Average Time Complexity: O(log n)
Worst Case Time Complexity: O(n)
--------------------------------------------------*/
struct Node *deleteNode(struct Node *root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        struct Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
int main()
{
    struct Node *root = NULL;
    int choice, value;
    struct Node *result;
    do
    {
        printf("\n\n===== BINARY SEARCH TREE MENU =====\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Search Specific Value (In-Between)\n");
        printf("4. Search Beginning Element (Minimum)\n");
        printf("5. Search End Element (Maximum)\n");
        printf("6. Display Inorder Traversal\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            printf("Node inserted successfully.\n");
            break;
        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            printf("Deletion operation completed.\n");
            break;
        case 3:
            printf("Enter value to search: ");
            scanf("%d", &value);
            result = search(root, value);
            if (result)
                printf("%d found in BST.\n", value);
            else
                printf("%d not found in BST.\n", value);

            break;
        case 4:
            if (root == NULL)
            {
                printf("BST is empty.\n");
            }
            else
            {
                result = findMin(root);
                printf("Beginning (Minimum) Element = %d\n",
                       result->data);
            }
            break;
        case 5:
            if (root == NULL)
            {
                printf("BST is empty.\n");
            }
            else
            {
                result = findMax(root);
                printf("End (Maximum) Element = %d\n",
                       result->data);
            }
            break;
        case 6:
            if (root == NULL)
                printf("BST is empty.\n");
            else
            {
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
            }
            break;
        case 0:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 0);
    return 0;
}