#include<stdio.h>
#define max 10
int isEmpty(int front){
        if(front==-1){
                printf("Queue is EMpty\n");
                return 1;
        }else{
                return 0;
        }
}
int isFull(int front,int rear){
        if((rear==(max-1)&&front==0)||(front==rear+1)){
                return 1;
        }else{
                return 0;
        }
}
void enqueue(int queue[],int *front,int *rear,int data){
        if(isFull(*front,*rear)){
		 printf("Queue is full\n");
        }else{
                 if(*rear==(max-1)&&*front>0){
                        *rear=0;
                }else{
                        (*rear)++;
                }

        if(*front==-1){
                *front=0;
        }
                queue[*rear]=data;

        }
}
int dequeue(int queue[],int *front,int *rear){
        int data;
        if(isEmpty(*front)){
                printf("Queue is Empty\n");
        }else{
                data=queue[*front];
                if(*front==*rear){
                        *front=-1;
                        *rear=-1;
                }else if(*front==(max-1)){
                        *front=0;
                }else{
                        (*front)++;
                }
        }
        return(data);
}
int peek(int queue[],int *front){
        if(isEmpty(*front)){
                return 1;
        }else{
                return(queue[*front]);
        }
}
int main(){
        int queue[max],front=-1,rear=-1,val;
        enqueue(queue,&front,&rear,1);
        enqueue(queue,&front,&rear,25);
        val=dequeue(queue,&front,&rear);
        printf("Data deleted :%d \n",val);
        printf("Top element of Queue : %d \n",peek(queue,&front));
return 0;
}

