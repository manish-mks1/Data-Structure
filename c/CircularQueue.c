#include <stdio.h>
#define MAX 5
int items[MAX];
int front = -1, rear = -1;
void display() {
  int i;
  if (front == -1)
    printf(" \n Empty Queue\n");
  else {
    printf("\n Front -> %d ", front);
    printf("\n Items -> ");
    for (i = front; i != rear; i = (i + 1) % MAX) {
      printf("%d ", items[i]);
    }
    printf("%d ", items[i]);
    printf("\n Rear -> %d \n", rear);
  }
}
void enQueue(int element) {
  if ((front == rear + 1) || (front == 0 && rear == MAX - 1))
    printf("\n Queue is full!! \n");
  else {
    if (front == -1) 
		front = 0;
    rear = (rear + 1) % MAX;
    items[rear] = element;
    printf("\n Inserted -> %d", element);
    display();
  }
  
}
void deQueue() {
  int element;
  if (front == -1)
    printf("\n Queue is empty !! \n");
  else {
    element = items[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    } 
    else {
      front = (front + 1) % MAX;
    }
    printf("\n Deleted element -> %d \n", element);
    display();
  }
}
int main() {
  int ch,ele;
    while (1)
    {
    	printf("\n******Circular QUEUE OPERATION******\n");
        printf("1.Enqueue Operation\n");
        printf("2.Dequeue Operation\n");
        printf("3.Display the Queue\n");
        printf("4.Exit\n");
        printf("Enter your choice of operations : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
            	printf("\nEnter element to insert:");
            	scanf("%d",&ele);
            	enQueue(ele);
            	break;
            case 2:
            	deQueue();
            	break;
            case 3:
            	display();
            	break;
            case 4:
            	exit(0);
            default:
            	printf("Invalid input\n");
        } 
    } 
  return 0;
}
