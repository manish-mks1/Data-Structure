#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *prev;
	int val;
	struct node *next;
};
void display(struct node *head){
	if(head!=NULL){
		printf("\n[ ");
		while(head!=NULL){
			printf("%d ",head->val);
			head=head->next;
		}
		printf(" ]");
	}
	else{
		printf("\nList is Empty..");
	}
}
void push(struct node **header,int ele){
	struct node *curr=*header;
	struct node *new_node=(struct node*) malloc(sizeof(struct node));
	if(*header==NULL){
		new_node->prev=*header;
		new_node->val=ele;
		new_node->next=*header;
		*header=new_node;
	}
	else{
		while(curr->next!=NULL){
			curr=curr->next;
		}
		new_node->val=ele;
		new_node->next=curr->next;
		new_node->prev=curr;
		curr->next=new_node;
	}
}
void insertionShortLinkedlist(struct node *head){
	struct node *curr=head;
	int tempval;
	struct node *temp;
	if(head==NULL){
		printf("\nList is empty...");
	}
	else if(curr->next==NULL){
		printf("\nList has only one elements..");
	}
	else{
		curr=curr->next;
		while(curr!=NULL){
			tempval=curr->val;
			temp=curr->prev;
			while(temp!=NULL){
				if(tempval<temp->val){
					temp->next->val=temp->val;
				}
				else{
					temp=temp->next;
					break;	
				}
				temp=temp->prev;
			}
			temp->val=tempval;
			curr=curr->next;
		}
	}
}
void main(){
	struct node *head=NULL;
	int ch,n,ele,i;
	while(1){
	printf("\n******** Linked List operation ********");
	printf("\n1. Push elements");
	printf("\n2. Pop elements");
	printf("\n3. Pop elements");
	printf("\n4. Bubble shorting");
	printf("\n5. Insertion shorting");
	printf("\n6. exit");
	printf("\nEnter your choice: ");
	scanf("%d",&ch);
	switch(ch){
		case 1:
			printf("****push elements****");
			printf("\n1.push one element");
			printf("\n2. Push n elements");
			printf("\nEnter your choice: ");
			scanf("%d",&ch);
			switch(ch){
				case 2:
					printf("\n****push n elements****");
					printf("\nEnter no of elements to push: ");
					scanf("%d",&n);
					for(i=1;i<=n;i++){
						printf("Enter %d element:",i);
						scanf("%d",&ele);
						push(&head,ele);
					}
					printf("\nPushed %d elements Sucessfully...\nYour list:",n);
					display(head);
					break;
				default:
					printf("\nInvalid Input..");
			}
			break;
		case 5:
			insertionShortLinkedlist(&head);
			printf("\nShorting Sucessfully...\nYour list:");
			display(head);
			break;
		case 6:
			display(head);
			break;
		case 7:
			exit(0);
		default:
			printf("\nInvalid Input..");
	}	
}
}
