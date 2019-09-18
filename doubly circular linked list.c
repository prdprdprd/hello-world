#include<stdlib.h>
#include<stdio.h>
struct Node{
        struct Node *prev;
        int data;
        struct Node *link;
};
void display(struct Node *ptr){
	struct Node *curr=ptr;
        printf("CONENTS Of CIRCULAR DOUBLY LINKED LIST :");
        do{
                printf(" %d->",curr->data);
                curr=curr->link;
        } while(curr!=ptr);
        printf("\b");
        printf("\b");
}
void reverse(struct Node *ptr){
        struct Node *curr=ptr;
   	printf(" REVERSE Of DOUBLY LINKED LIST :");
        do{
                printf(" %d->",curr->prev->data);
                curr=curr->prev;
        } while(curr!=ptr);
        printf("\b");
        printf("\b");

}
void create(struct Node **ptr,int d){
        *ptr=(struct Node *)malloc(sizeof(struct Node));
        (*ptr)->link=*ptr;
        (*ptr)->prev=*ptr;
        (*ptr)->data=d;
}
void insertAtEnd(struct Node *ptr,int d){
	struct Node *temp;
	temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=d;
	temp->prev=ptr->prev;
	temp->link=ptr;
	ptr->prev->link=temp;
	temp->link->prev=temp;
}
void insertInBeginning(struct Node **ptr,int d){
	struct Node *curr=*ptr;
	(*ptr)=(struct Node *)malloc(sizeof(struct Node));
	(*ptr)->data=d;
	(*ptr)->link=curr;
	(*ptr)->prev=curr->prev;
	curr->prev->link=*ptr;	
	curr->prev=*ptr;
}
void insertAfterSpecifiedNode(struct Node *ptr,int d,int key){
	struct Node *temp,*curr=ptr;
	temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=d;
	do{	
		if(curr->data==key){
			temp->link=curr->link;
			temp->prev=curr;
			curr->link=temp;
			temp->link->prev=temp;
			return ;
		}
		curr=curr->link;
	}while(curr!=ptr);
}
void deleteSpecifiedNode(struct Node **ptr,int key){
 	struct Node *curr=(*ptr),*temp1,*temp2;
        while(curr->data!=key){
                curr = curr->link;
                if(curr==(*ptr)){
                        printf("Key Not Found");
                        return;
                }
        }
        if(curr==(*ptr)){
                curr = curr->link;
                curr->prev = (*ptr)->prev;
                (*ptr) = curr;
                curr = curr->prev;
                curr->link = (*ptr);
        }
        else{
                temp1 = curr->link;
                temp2 = curr->prev;
                curr = temp2;
                curr->link = temp1;
                curr = temp1;
                curr->prev = temp2;
        }
}
int main(){
	struct Node *head=NULL;
	create(&head,2);
	insertAtEnd(head,3);
	insertInBeginning(&head,1);
	insertAfterSpecifiedNode(head,4,3);
	deleteSpecifiedNode(&head,1);
	deleteSpecifiedNode(&head,2);
	deleteSpecifiedNode(&head,3);
	deleteSpecifiedNode(&head,4);
	display(head);
	//reverse(head);
	return 0;
}
