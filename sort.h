int buff[10000];

void selSort(int num[] ,int n){//挿入ソート
	int i,j,k,min,temp;

	for(i=0;i<n;i++){
		min=num[i];//暫定的にnum[i]を最小値とする
		k=i;
		for(j=i+1;j<n;j++){
			if(num[j]<min){
				min=num[j];
				k=j;
			}
		}
		temp   = num[i];//変数をスワップ
		num[i] = num[k];
		num[k] = temp;
	}
}

void insSort(int num[] ,int n){//挿入ソート
	int i,j,temp;	
	for(i=0;i<n;i++){
		for(j=i;j>0 && num[j]<num[j-1];j--){
			temp    = num[j];//変数をスワップ
			num[j]  = num[j-1];
			num[j-1]= temp;
		}
	}
}

void bubSort(int num[] ,int n){//バブルソート
	int i,j,temp;
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(num[j]>num[j+1]){
				temp     = num[j];//変数をスワップ
				num[j]   = num[j+1];
				num[j+1] = temp;
			}
		}
	}
}

void quickSort(int array[],int left ,int right){
	int top = left,
		bottom = right,
		pivot = array[left+rand()%(right-left)+1];
	int tmp,i;
	while(top<=bottom){
		if(array[top]<pivot){
			top++;
			continue;
		}
		if(array[bottom]>pivot){
			bottom--;
			continue;
		}
		if(array[top]>=array[bottom]){
			tmp = array[top];
			array[top] = array[bottom];
			array[bottom] = tmp;
			top++;
			bottom--;
		}
	}
	if(left<bottom)quickSort(array,left,bottom);
	if(right>top)quickSort(array,top,right);
}

/*マージソート*/
void merge(int a[],int as,int b[],int bs,int c[]){
	int pa = 0;
	int pb = 0;
	int pc = 0;
	int i;
	while(pa<as && pb<bs){
		if(a[pa]<b[pb]){
			c[pc]=a[pa];
			pa++;
			pc++;
		}
		else {
			c[pc]=b[pb];
			pb++;
			pc++;
		}
	}
	while(pa<as){
		c[pc]=a[pa];
		pa++;
		pc++;
	}
	while(pb<bs){
		c[pc]=b[pb];
		pb++;
		pc++;
	}
}

void mergeSort(int array[],int first,int last){
	if(first<last){
		int center = (first+last)/2;
		int i;
		mergeSort(array,first,center);
		mergeSort(array,center+1,last);
		for(i=first;i<=last;i++){
			buff[i]=array[i];
		}
		merge(&buff[first],center-first+1,&buff[center+1],last-center,&array[first]);
	}
}

/*ヒープソート*/
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

void heapSort(int array[],int size){
	int tmp;
	int i;
	for(i=size/2;i>0;i--)downHeap(array,size,i);//ヒープ構造にする
	while(size>1){
	tmp = array[1];
	array[1] = array[size];
	array[size] = tmp;
	size-=1;
	downHeap(array,size,1);
	}
}

