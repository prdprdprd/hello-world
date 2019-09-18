#include<stdio.h>
int linearSearch(int a[],int key,int size){
        int i;
        for(i=0;i<size;i++){
                if(a[i]==key)
                        return(i);
        }
        return(-1);
}
int main(){
        int a[10]={20,5,45,8,16,53,14};
        int val;
        val=linearSearch(a,20,7);
        if(val==-1)
                printf("Key not found\n");
        else
                printf("Key found at position : %d \n", val);
        return 0;
}
