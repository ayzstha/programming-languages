// Aayush Shrestha | April 2, 2025
//  This program implements a stack using a linked list to store strings.
//  It provides a menu-driven interface for the user to push, pop, peek, and display the stack contents.

// Stack implementation in C using linked list to store strings
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

// Structure for a stack node
typedef struct Node
{
    char data[MAX_STRING_LENGTH];
    struct Node *next;
} Node;

// Function to push an item onto the stack
void push(Node **top, char *value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    strcpy(newNode->data, value);
    newNode->next = *top;
    *top = newNode;
}

// Function to pop an item off the stack
void pop(Node **top)
{
    if (*top == NULL)
    {
        printf("Stack is empty. Cannot pop.\n");
        return;
    }
    Node *temp = *top;
    *top = (*top)->next;
    printf("Popped: %s\n", temp->data);
    free(temp);
}

// Function to peek at the top item on the stack
void peek(Node *top)
{
    if (top == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Top: %s\n", top->data);
}

// Function to display the entire stack
void display(Node *top)
{
    printf("Stack contents:\n");
    if (top == NULL)
    {
        printf("[Empty Stack]\n");
        return;
    }
    Node *temp = top;
    while (temp)
    {
        printf("%s\n", temp->data);
        temp = temp->next;
    }
}

// Main function with menu-driven loop
int main()
{
    Node *top = NULL;
    int choice;
    char value[MAX_STRING_LENGTH];

    do
    {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume newline left in buffer

        switch (choice)
        {
        case 1:
            printf("Enter string to push: ");
            fgets(value, MAX_STRING_LENGTH, stdin);
            value[strcspn(value, "\n")] = 0; // Remove newline
            push(&top, value);
            break;
        case 2:
            pop(&top);
            break;
        case 3:
            peek(top);
            break;
        case 4:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
        display(top);
    } while (choice != 4);

    // Free memory before exiting
    while (top)
    {
        pop(&top);
    }

    return 0;
}
