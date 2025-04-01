/* Aayush Shrestha | April 2, 2025
This program implements a stack using a linked list to store strings.
It provides a menu-driven interface for the user to push, pop, peek, and display the stack contents. */

// Stack implementation in C using linked list to store strings
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRING_LENGTH 100

/*************************/
/* Structure definitions */
/*************************/
struct node
{
    char *value;
    struct node *next;
};
struct stack
{
    struct node *top;
};

/************************/
/* Function definitions */
/************************/
void push(struct stack *s, char value[])
{
    struct node *new_node = malloc(sizeof(struct node));
    new_node->value = malloc(STRING_LENGTH * sizeof(char));
    new_node->next = NULL;
    strcpy(new_node->value, value);
    new_node->next = s->top;
    s->top = new_node;
}

void pop(struct stack *s)
{
    struct node *old_top = s->top;
    if (old_top == NULL)
    {
        printf("Stack is empty. Cannot pop.\n");
        return;
    }
    s->top = old_top->next;
    printf("Popped: %s\n", old_top->value);
    free(old_top->value);
    free(old_top);
}

char *peek(struct stack s)
{
    if (s.top == NULL)
        return NULL;
    return s.top->value;
}

void display(struct stack s)
{
    struct node *n = s.top;
    printf("Stack contents:\n");
    if (n == NULL)
    {
        printf("[Empty Stack]\n");
        return;
    }
    while (n != NULL)
    {
        printf("%s\n", n->value);
        n = n->next;
    }
    printf("\n");
}

int menu(char *options[], int n)
{
    int i;
    printf("<<<< OPTIONS >>>>\n");
    for (i = 0; i < n; i++)
        printf("%d: %s\n", i + 1, options[i]);
    printf("Please enter an option (1-%d): ", n);
    scanf("%d", &i);
    getchar(); // To consume newline left in buffer
    return i;
}

/****************/
/* Main program */
/****************/
int main()
{
    struct stack s;
    char value[STRING_LENGTH];
    char *options[4] = {"Push", "Pop", "Peek", "Quit"};
    s.top = NULL;

    while (1)
    {
        switch (menu(options, 4))
        {
        case 1:
            printf("\nPlease enter a string to push onto the stack: ");
            fgets(value, STRING_LENGTH, stdin);
            value[strcspn(value, "\n")] = 0; // Remove newline
            push(&s, value);
            printf("\n");
            break;
        case 2:
            printf("\nRemoving the item from the top of the stack.\n\n");
            pop(&s);
            break;
        case 3:
            printf("\n\"%s\" is at the top of the stack.\n\n", peek(s) ? peek(s) : "[Empty Stack]");
            break;
        case 4:
            return 0;
        }
        display(s);
    }
    return 0;
}