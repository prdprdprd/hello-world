#include<stdlib.h>
#include<stdio.h>
struct Node{
	int data;
	struct Node *link;
};
void push(struct Node **ptr,int d){
                struct Node *temp;
		temp=(struct Node *)malloc(sizeof(struct Node));
               	temp->data=d;
               	temp->link=*ptr;
		*ptr=temp;

}
void pop(struct Node **ptr){
		if(*ptr==NULL){
			printf("Stack is Empty\n");
			return ;
		}
		*ptr=(*ptr)->link;
}
int peek(struct Node *ptr){
		if(ptr==NULL){
			printf("Stack is Empty\n");
			return (-1);
		}
			return (ptr->data);
}
int main(){
	struct Node *top=NULL;	
	push(&top,10);
	push(&top,12);
	peek(top);
	return 0;
}
