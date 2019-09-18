#include<stdio.h>
int binary_search(int a[],int key,int size){
	int low=0,high,mid,i=0;
	high=size-1;
	while(low<=high){
			mid=(low+high)/2;
			if(a[mid]==key){
				return(mid);
			}else if(a[mid]<key){
				low=mid+1;
			 }else if(a[mid]>key){
				high=mid-1;
		         } 
	}
	return(-1);
}
int main(){
	int a[10]={10,15,18,20,25,36,53};
	int val,key=99;
	val=binary_search(a,key,7);
	if(val==-1)
		printf("Key not Found\n");
	else
		printf("Key found at position : %d \n",val);
	return 0;
}
