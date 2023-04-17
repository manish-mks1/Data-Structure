#include <stdio.h>
#define MAX 10
void display(int *arr) {
  int i;
  printf("\n front:  ");
  for (i = 0; i < MAX; i++)
    printf("  %d", arr[i]);
  printf("  :rear");
}
int count(int *arr) {
  int c = 0, i;
  for (i = 0; i < MAX; i++) {
    if (arr[i] != 0)
      c++;
  }
  return c;
}
void addFront(int *arr, int item, int *pfront, int *prear) {
  int i, k, c;

  if (*pfront == 0 && *prear == MAX - 1) {
    printf("\nQueue is full.\n");
  }

  if (*pfront == -1) {
    *pfront = *prear = 0;
    arr[*pfront] = item;
  }

  if (*prear != MAX - 1) {
    c = count(arr);
    k = *prear + 1;
    for (i = 1; i <= c; i++) {
      arr[k] = arr[k - 1];
      k--;
    }
    arr[k] = item;
    *pfront = k;
    (*prear)++;
  } else {
    (*pfront)--;
    arr[*pfront] = item;
  }
}

void addRear(int *arr, int item, int *pfront, int *prear) {
  int i, k;

  if (*pfront == 0 && *prear == MAX - 1) {
    printf("\nDeque is full.\n");
    return;
  }

  if (*pfront == -1) {
    *prear = *pfront = 0;
    arr[*prear] = item;
    return;
  }

  if (*prear == MAX - 1) {
    k = *pfront - 1;
    for (i = *pfront - 1; i < *prear; i++) {
      k = i;
      if (k == MAX - 1)
        arr[k] = 0;
      else
        arr[k] = arr[i + 1];
    }
    (*prear)--;
    (*pfront)--;
  }
  (*prear)++;
  arr[*prear] = item;
}

int delFront(int *arr, int *pfront, int *prear) {
  int item;

  if (*pfront == -1) {
    printf("\nDeque is empty.\n");
    return 0;
  }

  item = arr[*pfront];
  arr[*pfront] = 0;

  if (*pfront == *prear)
    *pfront = *prear = -1;
  else
    (*pfront)++;

  return item;
}

int delRear(int *arr, int *pfront, int *prear) {
  int item;

  if (*pfront == -1) {
    printf("\nDeque is empty.\n");
    return 0;
  }

  item = arr[*prear];
  arr[*prear] = 0;
  (*prear)--;
  if (*prear == -1)
    *pfront = -1;
  return item;
}

int main() {
	int arr[MAX],ch,ele,front=-1, rear=-1, i,n;
	for(i=0;i<MAX;i++){
		arr[i]=0;
	}
	while (1)
	{
		printf("\n******DeQUEUE OPERATION******\n");
	    printf("1.Enqueue at front\n");
	    printf("2.Enqueue at Rear\n");
	    printf("3.Dequeue from front\n");
	    printf("4.Dequeue from Rear\n");
	    printf("5.Display the DeQueue\n");
	    printf("6.Exit\n");
	    printf("Enter your choice of operations : ");
	    scanf("%d", &ch);
	    switch (ch)
	    {
	        case 1:
	        	printf("\nEnter element :");
	        	scanf("%d",&ele);
	        	addFront(arr, ele, &front, &rear);
	        	display(arr);
	        	break;
	        case 2:
	        	printf("\nEnter element :");
	        	scanf("%d",&ele);
	        	addRear(arr, ele, &front, &rear);
	        	display(arr);
	        	break;
	        case 3:
	        	i = delFront(arr, &front, &rear);
  				printf("\nremoved item: %d", i);
  				printf("\nElements in a deque after deletion: ");
  				display(arr);
	        	break;
	        case 4:
	        	i = delRear(arr, &front, &rear);
  				printf("\nremoved item: %d", i);
  				printf("\nElements in a deque after deletion: ");
  				display(arr);
	        	break;
	        case 5:
	        	display(arr);
	        	break;
	        case 6:
	        	exit(0);
	        default:
	        	printf("Invalid input\n");
	    } 
	} 	
}
