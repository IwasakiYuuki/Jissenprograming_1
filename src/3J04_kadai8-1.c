#include <stdio.h>
#include <stdlib.h>

#define N 10000000

int binSearch(int *data,int search_data);

int main(){
	
	FILE *fp;
	int *data;
	char filename[256]="";
	long int input=0,flag=0,i=0;
	int ans=0;

	data=(int *)malloc(sizeof(int)*10000000);

	printf("input filename ->>");
	scanf("%s",filename);
	printf("input number ->>");
	scanf("%ld",&input);

	fp=fopen(filename,"r");

	for(i=0;i<N;i++){
		fscanf(fp,"%d",&data[i]);
	}
	printf("aaaa\n");

	ans=binSearch(data,input);

	if(ans==-1){
		printf("該当はありません.\n");
		return -1;
	}else{
		printf("%d番目\n",ans);
	}

	return 0;
}

int binSearch(int *data,int search_data){
	
	int ans=0,left=0,right=0,m=0,count=0;

	left=0;
	right=N-1;

	while(left<right){
		m=(left+right)/2;
		if(data[m]>search_data){
			right=m;
		}else if(data[m]<search_data){
			left=m;
		}else if(data[m]==search_data){
			return m;
		}
		count++;
		if(count>24)break;
	}
	return -1;
}
