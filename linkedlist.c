#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
// Display Linked List: Time Complexity: O(n)
void display()
{
    struct Node *temp = head;
    if (head == NULL)
    {
        printf("Linked List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
// Insert at Beginning: Time Complexity: O(1)
void insertBeginning(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("Node inserted at beginning.\n");
}
// Insert at End: Time Complexity: O(n)
void insertEnd(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Node inserted at end.\n");
}
// Insert at Position: Time Complexity: O(n)
void insertPosition(int value, int pos)
{
    int i;
    struct Node *newNode, *temp;
    if (pos == 1)
    {
        insertBeginning(value);
        return;
    }
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Invalid Position.\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node inserted at position %d.\n", pos);
}
// Delete from Beginning: Time Complexity: O(1)
void deleteBeginning()
{
    struct Node *temp;
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    temp = head;
    head = head->next;
    free(temp);
    printf("Node deleted from beginning.\n");
}
// Delete from End: Time Complexity: O(n)
void deleteEnd()
{
    struct Node *temp, *prev;
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        printf("Node deleted from end.\n");
        return;
    }
    temp = head;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
    printf("Node deleted from end.\n");
}
// Delete from Position: Time Complexity: O(n)
void deletePosition(int pos)
{
    int i;
    struct Node *temp, *prev;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    if (pos == 1)
    {
        deleteBeginning();
        return;
    }
    temp = head;
    for (i = 1; i < pos && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Invalid Position.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Node deleted from position %d.\n", pos);
}
// Search Element: Time Complexity: O(n)
void search(int key)
{
    int position = 1;
    struct Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("Element found at position %d.\n", position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Element not found.\n");
}
int main()
{
    int choice, value, pos;
    do
    {
        printf("\n===== LINKED LIST MENU =====\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Search Element\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertBeginning(value);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insertEnd(value);
            break;
        case 3:
            printf("Enter value: ");
            scanf("%d", &value);
            printf("Enter position: ");
            scanf("%d", &pos);
            insertPosition(value, pos);
            break;
        case 4:
            deleteBeginning();
            break;
        case 5:
            deleteEnd();
            break;
        case 6:
            printf("Enter position: ");
            scanf("%d", &pos);
            deletePosition(pos);
            break;
        case 7:
            printf("Enter element to search: ");
            scanf("%d", &value);
            search(value);
            break;
        case 8:
            display();
            break;
        case 9:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid Choice.\n");
        }
    } while (choice != 9);
    return 0;
}