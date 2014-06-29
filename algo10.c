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

int insert(int array[],int *num,int size,int x){ //要素を挿入
	*num+=1;
	if(*num>size)return 0;//サイズを超えた場合失敗
	array[*num]=x;
	upHeap(array,*num);
	return 1;
}

int delete(int array[],int *num,int *x){ //根の要素を削除
	if(*num<1)return 0;//要素が無い場合失敗
	array[1] = array[*num];
	array[*num] = 0;
	*num-=1;
	downHeap(array,*num,1);
	return 1;
}

void main(){
	int a[10]={0,6,5,5,3,4};
	int size=5;
	int i;
	insert(a,&size,10,7);
	delete(a,&size,0);
	for(i=1;i<=size;i++){
		printf("%d ",a[i]);
	}
}
