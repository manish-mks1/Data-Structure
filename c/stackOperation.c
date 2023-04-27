#include <stdio.h>
#include <stdlib.h>
#define MAX 4
int array[MAX],top = -1;
void show()
{
	int i;
    if (top == -1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nStack elements: \n");
        for (i = top; i >= 0; --i)
            printf("%d ", array[i]);
    }
}
void push()
{
    int x;

    if (top == MAX - 1)
    {
        printf("\nOverflow!!");
    }
    else
    {
        printf("\nEnter the element to be added onto the stack: ");
        scanf("%d", &x);
        top = top + 1;
        array[top] = x;
        show();
    }
}

void pop()
{
    if (top == -1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nPopped element: %d", array[top]);
        top = top - 1;
        show();
    }
}


void main()
{
    int ch;
    while (1)
    {
        printf("\nPerform operations on the stack:");
        printf("\n1.Push the element\n2.Pop the element\n3.Show\n4.Exit");
        printf("\n\nEnter the choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            show();
            break;
        case 4:
            exit(0);

        default:
            printf("\nInvalid Input..");
        }
    }
}


