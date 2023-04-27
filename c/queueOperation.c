#include <stdio.h>
# define MAX 10
int arr[MAX];
int Rear = - 1;
int Front = - 1;
void show(){
    int i;
    if (Front == - 1)
        printf("\nEmpty Queue ");
    else
    {
        printf("\nQueue Elements: ");
        for (i = Front; i <= Rear; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
}
void enqueue(){
    int item;
    if (Rear == MAX - 1)
       printf("\nOverflow ");
    else
    {
        if (Front == - 1)
        	Front = 0;
        printf("\nEnter Element: ");
        scanf("%d", &item);
        Rear = Rear + 1;
        arr[Rear] = item;
        show();
    }
} 
 
void dequeue(){
    if (Front == - 1 || Front > Rear)
    {
        printf("\nUnderflow ");
        return ;
    }
    else
    {
        printf("\nElement deleted from the Queue: %d", arr[Front]);
        Front = Front + 1;
        show();
    }
} 
void main(){
    int ch;
    while (1)
    {
    	printf("\n****Queue operation*****\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            	enqueue();
            	break;
            case 2:
            	dequeue();
            	break;
            case 3:
            	show();
            	break;
            case 4:
            	exit(0);
            default:
            	printf("Invalid choice.. \n");
        } 
    } 
} 
 

