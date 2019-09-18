#include<stdio.h>
#include<stdlib.h>
struct Node{
        struct Node *left;
        int data;
        struct Node *right;
};
typedef struct Node node;

void insert(node **r,int key){
        node *temp,*curr,*par;
        temp=(node*)malloc(sizeof(node));
        temp->data=key;
        temp->left=NULL;
        temp->right=NULL;
        curr=(*r);
        if((*r)==NULL)
                *r=temp;
        else{
          while(curr!=NULL){
                par=curr;
                if(key<curr->data){
                        curr=curr->left;
                }else{
                        curr=curr->right;
                }
          }
          if(key<par->data){
                par->left=temp;
          }else{
                par->right=temp;
         }
        }
}

void inorder(node *r){
        if(r!=NULL){
                inorder(r->left);
                printf("%d \n",r->data);
                inorder(r->right);
        }
}

void search(node **r,int data){
        node *curr=*r;
        while(curr!=NULL){
                if(curr->data==data){
                        printf("key found\n");
                        return;
                }else if(data<curr->data){
                        curr=curr->left;
                }else{
                        curr=curr->right;
                }
        }
        printf("Key not found\n");
}

int main(){
        int val;
        node *root=NULL;
        insert(&root,8);
        insert(&root,15);
        insert(&root,20);
        insert(&root,25);
        inorder(root);
        search(&root,20);
        return 0;
}

