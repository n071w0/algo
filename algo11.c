#include <stdio.h>

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
	if((array[n]<array[2*n] || array[n]<array[2*n+1]) &&
	 (2*n <= num)){
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
	int i;
	while(num>1){
	tmp = array[1];
	array[1] = array[num];
	array[num] = tmp;
	num-=1;
	downHeap(array,num,1);
	}
}

void main(){
	int a[11]={0,7,16,3,4,5,11,9};
	int size=7;
	int i;
	for(i=size/2;i>0;i--)downHeap(a,size,i);
	heapSort(a,size);
	for(i=1;i<=size;i++){
		printf("%d ",a[i]);
	}
}
