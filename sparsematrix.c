#include<stdio.h>
#include<stdlib.h>
typedef struct mat * Mat;
struct mat{
	int row,col,data;
	Mat link;
};
int create(Mat *head,int row,int col,int data){
	Mat temp=(Mat)malloc(sizeof(struct mat));
	temp->row=row;
	temp->col=col;
	temp->data=data;	
	temp->link=(*head);	
	(*head)=temp;
}
int display(Mat head){
	Mat curr= head;
	while(curr!=NULL){
	printf("%d %d %d\n",curr->row,curr->col,curr->data);
	curr=curr->link;
}
}
int main(){
	Mat head=NULL;
	int sparse[20][20]={0};
	int c,r,i,j,a,b,n,data;
	printf("\nEnter the number rows of sparse matrix: ");
	scanf("%d",&r);
	printf("\nEnter the number of columns of sparse matrix");
	scanf("%d",&c);	
	printf("Enter the Number of non zero elements:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
			printf("Enter the row no of %d element:",i+1);
			scanf("%d",&a);
			printf("Enter the column no of %d element:",i+1);
			scanf("%d",&b);
			printf("Enter the data of %d element:",i+1);
			scanf("%d",&data);
			sparse[a][b]=data;			
	}
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			if(sparse[i][j]!=0){
				create(&head,i,j,sparse[i][j]);
			}
		}
	}
	create(&head,r,c,n);
	display(head);
}
