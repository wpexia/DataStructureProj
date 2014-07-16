# include "stdio.h"
# include "stdlib.h"
# include "time.h"
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
	for(i = 0; i < n; i ++) dd[ i ] = rand()%32768;
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
}

void myxier(){
}

void mykuaisu(){
}

void mydui(){
}

void myguibing(){
}

void myjishu(){
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
