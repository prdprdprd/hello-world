#include<stdio.h>
#include "stack.h"
void strrev(char stack[],char str1[],char str2[],int *top){
	int i,j=0;
	for(i=0;str1[i]!='\0';i++){
		push(stack,str1[i],top);
	}
	while(*top!=-1){
		str2[j++]=pop(stack,top);
	}
}
int main(){
	int top=-1;
	char stack[MAX],str1[20]="Hello",str2[20];
	printf("Original String : %s\n",str1);
	strrev(stack,str1,str2,&top);
	printf("Reversed String : %s\n",str2);
	return 0;
}
	

	
