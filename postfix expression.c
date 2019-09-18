#include<stdio.h>
//#include<ctype.h>
#include "stack.h"
#define MAX 20
int evaluate(char postfix[],char stack[]){
	int i,j,o1,o2,flag=0,y;
	for(i=0;postfix[i]!='\0';i++){
		if(postfix[i]>='0'&&postfix[i]<='9'){
			push(stack,postfix[i]-48);
			/*if(flag==1){
				y=pop(stack);
				push(stack,(postfix[i]-48)+10*y);
			}else if(flag==0){
				push(stack,postfix[i]-48);
			}
		}else if(postfix[i]==' '){
				flag=0;
		}*/}else{
			o1=pop(stack);
			o2=pop(stack);
			switch(postfix[i]){
				case '*':
					j=o2*o1;
					break;
				case '/':
                                        j=o2/o1;
					break;
				case '+':
                                        j=o2+o1;
					break;
				case '-':
                                        j=o2-o1;
					break;
			}
			push(stack,j);					
		}
	}
	return pop(stack);
}	
int main(){
	char postfix[MAX]="123*+";
	int val;
	char stack[MAX];
	val=evaluate(postfix,stack);
	printf("Evaluation of %s : %d\n",postfix,val);
	return 0;
}
