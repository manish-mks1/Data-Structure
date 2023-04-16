#include<stdio.h>
#define row 5
#define col 5
void main(){
	int i,j,rw,cl,arr[row][col],*p;
	printf("Enter no of rows:");
	scanf("%d",&rw);
	printf("Enter no of column: ");
	scanf("%d",&cl);
	for(i=0;i<rw;i++){
		for(j=0;j<cl;j++){
			printf("N(%d,%d):",i+1,j+1);
			scanf("%d",(arr+(i*cl+j)));
		}
	}
//	for(p=&arr[0][0];p<=&arr[rw-1][cl-1];p++)
//	printf("%d",*p);
	for(i=0;i<rw;i++){
		for(j=0;j<cl;j++){
			printf("%3d",*(*(arr+i)+j));
		}
		printf("\n");
	}
//	printf("%d",*(*(arr+1)+1));
}