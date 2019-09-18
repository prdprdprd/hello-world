#include<stdio.h>
#define MAX 20
int top=-1;
void push(char stack[],char data){
	if(top==(MAX-1)){
		printf("Stack overflow\n");
	}else{
		top++;
		stack[top]=data;
	}
}
char pop(char stack[]){
	char data;
	if(top==-1){
		printf("Stack underflow\n");
		return(-1);
	}else{
		data=stack[top];
		top--;
		return(data);
	}
}
int prior(char ch){
	switch(ch){
		case '$':
		case '!':
		case '^':
			return 4;
		case '*':
		case '/':
		case '%':
		case '?':
			return 3;
		case '+':
		case '-':
			return 2;
		case '=':return 1;
		case '(':
			return 0;
	}
}
void infixToPostfix(char infix[],char postfix[],char stack[]){
	int i,j=0;
	char val;
	for(i=0;infix[i]!='\0';i++){
		if((infix[i]>='a'&&infix[i]<='z')||(infix[i]>='A'&&infix[i]<='Z')){
			postfix[j]=infix[i];
			j++;
		}else if(infix[i]=='('){
			push(stack,infix[i]);
		}else if(infix[i]==')'){
			do{
				val=pop(stack);
				if(val!='('){
					postfix[j++]=val;
				}
			}while(val!='(');
		}else{
			if(top!=-1){
				while(prior(stack[top])>=prior(infix[i])){
					postfix[j++]=pop(stack);
				}
			}
			push(stack,infix[i]);
		}
	}
	while(top!=-1){
		postfix[j++]=pop(stack);
	}
}
int main(){
	char infix[20]="z=a-b^(c*d)";
	char postfix[MAX];
	char stack[MAX];
	infixToPostfix(infix,postfix,stack);
	printf("Postfix Expression : %s\n",postfix);
	return 0;
}
