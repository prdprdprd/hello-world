#include<stdio.h>
int main(){
		int a[5]={8,4,6,9,1};
		int i,j,min,temp;
		printf("Array before sorting\n");
		for(i=0;i<5;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
		for(i=0;i<4;i++){
			min=i;
			for(j=i+1;j<5;j++){
				if(a[j]<a[min])
					min=j;
			}
			if(min!=i){
				temp=a[min];
				a[min]=a[i];
				a[i]=temp;
			}
		}
		printf("Array after sorting \n");
		for(i=0;i<5;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
		return 0;
}
		
