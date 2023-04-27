#include<stdio.h>
#include<conio.h>
#define row 3
#define col 3
void main(){
	int arr1[row][col],arr2[row][col],sum=0,arradd[row][col],rw,cl,i,j,n;
	clrscr();
	printf("Enter matrix row & column:--\n");
	printf("Enter no of row:");
	scanf("%d",&rw);
	printf("Enter no of column:");
	scanf("%d",&cl);
	printf("Enter elements of first matrix:--\n");
	for(i=0;i<rw;i++)
		for(j=0;j<cl;j++){
			printf("N(%d,%d): ",i+1,j+1);
			scanf("%d",*arr1+(i*cl+j));
		}
	printf("Enter elements of second matrix:--\n");
	for(i=0;i<rw;i++)
		for(j=0;j<cl;j++){
			printf("N(%d,%d): ",i+1,j+1);
			scanf("%d",*arr2+(i*cl+j));
		}
	printf("\nYour first matrix:\n");
	for(i=0;i<rw;i++){
		for(j=0;j<cl;j++){
			printf("%3d",*(*(arr1+i)+j));
		}
		printf("\n");
	}
	printf("\nYour second matrix:\n");
	for(i=0;i<rw;i++){
		for(j=0;j<cl;j++){
			printf("%3d",*(*(arr2+i)+j));
		}
		printf("\n");
	}
	for(i=0;i<rw;i++){
		for(j=0;j<cl;j++){
			*(*(arradd+i)+j)= (*(*(arr1+i)+j)) + (*(*(arr2+i)+j));
		}
	}
	printf("\nYour Addition of:\n");
	for(i=0;i<rw;i++){
		for(j=0;j<cl;j++){
			printf("%4d",*(*(arradd+i)+j));
		}
		printf("\n");
	}

	getch();
}

