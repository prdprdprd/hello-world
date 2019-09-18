#include<stdio.h>
#define MAX 10
int isFull(int f,int r){
	if(r==MAX-1 && f==0)
		return 1;
	else
		return 0;
}
int isEmpty(int f){
	if(f==-1)
		return 1;
	else
		return 0;
}
void enqueue(char queue[],int *f,int *r,char data){
	if(isFull(*f,*r))
		printf("Queue Overflown\n");
	else{
		(*r)++;
		queue[*r]=data;
		if(*f==-1)
			*f=0;
	}
}
char dequeueF(char queue[],int *f,int *r){
	char data,error='@';
	if(isEmpty(*f)){
		printf("Queue Underflown\n");
		return error;
	}else{
		data=queue[*f];
		if(*f==*r){
			*f=-1;
			*r=-1;
		}else{
			(*f)++;
	}
		return data;
	}
}
char dequeueR(char queue[],int *f,int *r){
	char data,error='@';
	if(isEmpty(*f)){
		printf("Queue Underflown\n");
		return error;
	}else{
		data=queue[*r];
		if(*f==*r){
			*f=-1;
			*r=-1;
		}else{
			(*r)--;
		}
		return data;
	}
}
void checkPalindrome(char queue[],int *f,int *r,char str[]){
	char a,b;
	int i;
	for(i=0;str[i]!='\0';i++){
		enqueue(queue,f,r,str[i]);
	}
	while(*f!=*r){
		a=dequeueF(queue,f,r);
		b=dequeueR(queue,f,r);
		if(a!=b){
			printf("Given string is not a Palindrome\n");
			return ;
		}
	}
	printf("Given string is palindrome\n");
}
int main(){
	int rear=-1,front=-1;
	char queue[MAX],str[MAX]="MADAM";
	printf("Input string :%s \n",str);
	checkPalindrome(queue,&front,&rear,str);
	return 0;
}








