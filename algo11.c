#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void upHeap(int array[],int n){
	int tmp;
	if(array[n]>array[n/2] && n>1){
		tmp=array[n];
		array[n]=array[n/2];
		array[n/2]=tmp;
		upHeap(array,n/2);
	}
}

void downHeap(int array[],int num,int n){
	int tmp;
	if((array[n]<array[2*n] && 2*n <= num) ||
	 (array[n]<array[2*n+1] && 2*n+1 <=num)){
		if(array[2*n]<array[2*n+1] && 2*n+1 <=num){
			tmp=array[n];
			array[n]=array[2*n+1];
			array[2*n+1]=tmp;
			downHeap(array,num,2*n+1);
		}
		else {
			tmp=array[n];
			array[n]=array[2*n];
			array[2*n]=tmp;
			downHeap(array,num,2*n);
		}
	}
}

void heapSort(int array[],int num){ //根の要素を削除
	int tmp;
	while(num>1){
	tmp = array[1];
	array[1] = array[num];
	array[num] = tmp;
	num-=1;
	downHeap(array,num,1);
	}
}

void main(){
	int a[11]={0};
	int size=10;
	int i;
	srand((unsigned int)time(0));
	printf("Reverse\nBefore:");
	for(i=1;i<11;i++){
		a[i]=11-i;
		printf("%d ",a[i]);
	}
	printf("\nAfter:");
	for(i=size/2;i>0;i--)downHeap(a,size,i);
	heapSort(a,size);
	for(i=1;i<=size;i++){
		printf("%d ",a[i]);
	}
	printf("\nRandom\nBefore:");
	for(i=1;i<11;i++){
		a[i]=rand()%20+1;
		printf("%d ",a[i]);
	}
	printf("\nAfter:");
	for(i=size/2;i>0;i--)downHeap(a,size,i);
	heapSort(a,size);
	for(i=1;i<=size;i++){
		printf("%d ",a[i]);
	}

}
