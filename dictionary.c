
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Dictionary{
        char key[10];
        char meaning[40];
        struct Dictionary *link;
};
typedef struct Dictionary D;
int key_val(char key[]){
        int val=0;
        /*while(key[i]!='\0'){
                val+=key[i];    
        }*/
        val=key[0]-97;
        return val;
}
void insert(D *hashTable[],char k[],char m[]){
        D *temp;
        int key1=0;
        key1=key_val(k);
        //printf("%d\n",key1);
        temp=(D *)malloc(sizeof(D));
        strcpy(temp->key,k);
        strcpy(temp->meaning,m);
        temp->link=hashTable[key1];
        hashTable[key1]=temp;
}
void search(D *hashTable[],char k[]){
        D *ptr;
        int key1=key_val(k);
        ptr=hashTable[key1];
        while(ptr!=NULL){
                if(!(strcmp(ptr->key,k))){
                        printf("\tKeyword:%s  Meaning:%s\n",ptr->key,ptr->meaning);
                        return ;
                }
                ptr=ptr->link;
        }
        printf("\tKey not found\n");
}
void display(D *hashTable[]){
        int i=0;
        while(i<25){
                if(hashTable[i]!=NULL){
                        printf("Keyword:%s Meaning:%s\n",hashTable[i]->key,hashTable[i]->meaning);
                }
                i++;
        }
}
int main(){
        D * hashTable[26]={NULL};
        insert(hashTable,"cat","animal");
        insert(hashTable,"dog","animal");
        insert(hashTable,"Cat","animal");
        //printf("%s %s\n",hashTable[2]->key,hashTable[2]->meaning);
        //display(hashTable);
        search(hashTable,"CAT");
        search(hashTable,"dog");
        return 0;
}
