#include<stdio.h>
#define max 4
int isFull(int top){
        if(top==max-1)
                return 1;
        return 0;
}
int isEmpty(int top){
        if(top==-1)
                return 1;
        return 0;
}
void push(int stack[],int*top,int data){
        if(isFull(*top)){
                printf("Stack is overflow\n");
        }else{
                (*top)++;
                stack[*top]=data;
        }
}
int pop(int stack[],int *top){
        int data;
        if(isEmpty(*top)){
                printf("Stack is underflow\n");
                return -1;
        }else{
                data=stack[*top];
                (*top)--;
                return(data);
        }
}
int peek(int stack[],int top){
        int data;
        if(isEmpty(top)){
                printf("Stack is Empty\n");
                return -1;
        }else{
                return(stack[top]);
        }
}

int main(){
        int stack[max],data=10,top=-1;
        push(stack,&top,10);
        push(stack,&top,20);
        push(stack,&top,30);
        data=pop(stack,&top);
        printf("Data pop from stack %d \n",data);
        printf("Top elements of stack is %d \n",peek(stack,top));
        return 0;
}


