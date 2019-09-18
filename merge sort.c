#include<stdio.h>
void merge(int arr[],int l,int m,int r){
		int i=0,j=0,k=1;
		int s1=m-l+1;
		int s2=r-m;
		int a1[s1],a2[s2];
		for(i=0;i<s1;i++){
			a1[i]=arr[l+i];
		}
		for(j=0;j<s2;j++){
                        a2[j]=arr[m+1+j];
                }
		i=0;
		j=0;
		k=l;
		while(i<s1&&j<s2){
			if(a1[i]<=a2[j]){
				arr[k]=a1[i];
				i++;
			}else{
				arr[k]=a2[j];
				j++;
			}
			k++;
		}
		while(i<s1){
			arr[k]=a1[i];
			i++;
			k++;
		}
		while(j<s2){
			arr[k]=a2[j];
			j++;
			k++;
		}
}
void mergeSort(int arr[],int l,int r){
         int m;
         if(l<r){
                m=(l+r)/2;
                mergeSort(arr,l,m);
                mergeSort(arr,m+1,r);
                merge(arr,l,m,r);
        }
}
void print(int arr[],int size){
		int i;
		for(i=0;i<size;i++){
			printf(" %d ",arr[i]);
		}
		printf("\n");
}		
int main(){
		int arr[5]={7,6,9,8,-1};
		printf("Array before sorting\n");
		print(arr,5);
		mergeSort(arr,0,4);	
		printf("Array after sorting\n");	
		print(arr,5);
		return 0;
}
