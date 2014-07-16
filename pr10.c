# include "stdio.h"
# include "stdlib.h"
# include "time.h"

#define WIDTH 20 
#define MAXK 10

int n=0;
long num;
int da[2000000];
int dd[2000000];
void myhead(){
	printf("**     排序算法比较      **\n");
	printf("===========================\n");
	printf("**     1 ---冒泡排序     **\n");
	printf("**     2 ---选择排序     **\n");
	printf("**     3 ---直接插入排序 **\n");
	printf("**     4 ---希尔排序     **\n");
	printf("**     5 ---快速排序     **\n");
	printf("**     6 ---堆排序       **\n");
	printf("**     7 ---归并排序     **\n");
	printf("**     8 ---基数排序     **\n");
	printf("**     9 ---退出程序     **\n");
	printf("===========================\n");
	printf("\n");
}

void myrand(){
	int i;
	srand((unsigned)time(NULL)); /*随机种子*/
	for(i = 0; i < n; i ++) dd[ i ] = rand();
}

void myinit(){
	int i;
	for(i = 0; i < n; i ++) da[ i ] = dd[ i ];
	num=0;
}

inline void swap(int *a,int *b){
int temp;
temp=*a;
*a=*b;
*b=temp;
num++;
}
void mymaopao(){
	clock_t t1 = clock();
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=n-1;j>i;j--){
			if(da[j]<da[j-1])
			swap(&da[j],&da[j-1]);
		}
	clock_t t2 = clock();
	long sec = (t2-t1) / CLOCKS_PER_SEC;
	printf("冒泡排序所用时间：        %ld秒\n",sec);
	printf("冒泡排序所用交换次数：    %ld\n",num);
}

void myxuanzhe(){
	clock_t t1 = clock();
	int i,j,temp;
	for(i=0;i<n-1;i++){
		temp=i;
		for(j=i+1;j<n;j++){
			if(da[j]<da[temp]){temp=j;num++;}
		}
		if(temp!=i)swap(&da[temp],&da[i]);
	}
	clock_t t2 = clock();
	long sec = (t2-t1) / CLOCKS_PER_SEC;
	printf("选择排序所用时间：        %ld秒\n",sec);
	printf("选择排序所用交换次数：    %ld\n",num);
}

void mycharu(){
	clock_t t1 = clock();
	int i,j;
	int temp=0;
	for(i = 1; i < n ; i++){
		temp = da[i];
		for(j = i; j > 0&& temp < da[j - 1]; j--){
			if(temp < da[j - 1])
				swap(&da[j],&da[j-1]);
		}
		da[j] = temp;
	}	
	clock_t t2 = clock();
	long sec = (t2-t1) / CLOCKS_PER_SEC;
	printf("插入排序所用时间：        %ld秒\n",sec);
	printf("插入排序所用交换次数：    %ld\n",num);
}

void myxier(){
	clock_t t1 = clock();
	int i, j, k;
	int temp, gap;  
	for (gap = n / 2; gap > 0; gap /= 2){
        	for (i = 0; i < gap; i++){
			for (j = i + gap; j < n; j += gap)
				if (da[j] < da[j - gap]){
					temp = da[j];  
					k = j - gap;
					while (k >= 0 && da[k] > temp){
						da[k + gap] = da[k];
						k -= gap;
					}
					da[k + gap] = temp;
					num++;
				}
		}
	}
	clock_t t2 = clock();
	long sec = (t2-t1) / CLOCKS_PER_SEC;
	printf("希尔排序所用时间：        %ld秒\n",sec);
	printf("希尔排序所用交换次数：    %ld\n",num);
}

void myqsort(int l,int r) {
	int i, j, x;
	if (l < r){
		i = l;
		j = r;
		x = da[i];
		while (i < j){
			while(i < j && da[j] > x) j--; /* 从右向左找第一个小于x的数 */
			if(i < j) da[i++] = da[j];
			while(i < j && da[i] < x) i++; /* 从左向右找第一个大于x的数 */
			if(i < j) da[j--] = da[i];
		}
		da[i] = x;
		num++;
		myqsort(l, i-1); /* 递归调用 */
		myqsort(i+1, r);
	}
}
void mykuaisu(){
	clock_t t1 = clock();
	myqsort(0,n);	
	clock_t t2 = clock();
	long sec = (t2-t1) / CLOCKS_PER_SEC;
	printf("希尔排序所用时间：        %ld秒\n",sec);
	printf("希尔排序所用交换次数：    %ld\n",num);
}
void HeapAdjust(int i, int nLength){
	int nChild, nTemp;
	for (nTemp = da[i]; 2 * i + 1 < nLength; i = nChild){
        	nChild = 2 * i + 1;
        	if (nChild != nLength - 1 && da[nChild + 1] > da[nChild])
            	++nChild;
        	if (nTemp < da[nChild]){
			da[i] = da[nChild];
			num++;
        	}else{
			break;
		}
	}
	da[i] = nTemp;
}
void mydui(){
	clock_t t1 = clock();
	int i;
	for (i = n / 2 - 1; i >= 0; --i){
		HeapAdjust(i, n);
	}
	for (i = n - 1; i > 0; --i){
		swap(&da[0], &da[i]);
        HeapAdjust(0, i);
	}
	clock_t t2 = clock();
	long sec = (t2-t1) / CLOCKS_PER_SEC;
	printf("堆排序所用时间：        %ld秒\n",sec);
	printf("堆排序所用交换次数：    %ld\n",num);
}
void Merge(int left, int m, int right){
	int aux[200000] = {0};
    	int i;
    	int j;
    	int k;
    
    	for (i = left, j = m+1, k = 0; k <= right-left; k++){
		num++;
        	if (i == m+1){
            		aux[k] = da[j++];
           		continue;
        	}
        	if (j == right+1){
            		aux[k] = da[i++];
            		continue;
        	}
        	if (da[i] < da[j]){
            		aux[k] = da[i++];
        	}else{
            		aux[k] = da[j++];
		}
    	}
	for (i = left, j = 0; i <= right; i++, j++){
		da[i] = aux[j];
	}
}
void MergeSort(int start,int end){
	if (start < end){
        	int i;
        	i = (end + start) / 2;
                MergeSort(start, i);
                MergeSort(i + 1, end);
	        Merge(start, i, end);
    }
}
void myguibing(){
	clock_t t1 = clock();
	MergeSort(0,n-1);
	clock_t t2 = clock();
	long sec = (t2-t1) / CLOCKS_PER_SEC;
	printf("归并排序所用时间：        %ld秒\n",sec);
	printf("归并排序所用交换次数：    %ld\n",num);
}
int getDValue(int value, int d) {
	for (;d > 0 && value > 0; d--) {
		value = value / MAXK;
	}
	return value % MAXK;
}
void myjishu(){
	clock_t t1 = clock();
	int i;
	void innerCountingSort(int d);
	for (i = 0; i < WIDTH; i++) {
		innerCountingSort(i);
	}
	clock_t t2 = clock();
	long sec = (t2-t1) / CLOCKS_PER_SEC;
	printf("基数排序所用时间：        %ld秒\n",sec);
	printf("基数排序所用交换次数：    %ld\n",num);
}

void innerCountingSort(int d) {
	int i, j, x, k[MAXK] = {0};
	int *ip = (int *)malloc(n * sizeof(int));
	int *bp = (int *)malloc(n * sizeof(int));
	int getDValue(int value, int d);
	for (i = 0; i < n; i++) {
		ip[i] = getDValue(da[i], d);
		k[ip[i]]++;
	}

	for (j = 1; j < MAXK; j++) {
		k[j] = k[j] + k[j-1];
	}

	for (i = n - 1; i >= 0; i--) {
		bp[k[ip[i]] - 1] = da[i];
		k[ip[i]]--;
	}

	for (i = 0; i < n; i++) {
		da[i] = bp[i];
	}

	free(ip);
	free(bp);
}


int main()
{
	myhead();
	printf("请输入要产生的随机数的个数（不超过10000）：");
	scanf("%d",&n);
	myrand(n);
	printf("\n");
	int flag = 1;
	while (flag){	
		myinit();	
		printf("\n");	
		printf("请选择排序算法：");
		int ch;
		scanf("%d", &ch);
		switch(ch){
			case 1 : mymaopao(); break;
			case 2 : myxuanzhe(); break;
			case 3 : mycharu(); break;
			case 4 : myxier(); break;
			case 5 : mykuaisu(); break;
			case 6 : mydui(); break;
			case 7 : myguibing(); break;
			case 8 : myjishu(); break;
			case 9 : flag = 0;	
		}
	}
	return 0;
}
