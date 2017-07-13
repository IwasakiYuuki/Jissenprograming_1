#include <stdio.h>
#include <stdlib.h>

#define N 1000000

void msort(int data[],int left,int right);

int main(){
	

//	printf("pls input number-->");
	
//	for(i=0;i<10;i++){
//		scanf("%d",&data[i]);
//	}
	
	char filename[256];
	int data[N],i;
	FILE *fp;

	printf("pls enter InputFileName...-->");
	scanf("%s",filename);

	fp=fopen(filename,"r");
	
	if(fp==NULL){
		printf("ERROR : can not open file.\n");
		exit(1);
	}else{
		printf("[*]Complate openning file.\n");
	}

	for(i=0;i<N;i++){
		fscanf(fp,"%d",&data[i]);
	}
	printf("[*]Complate loading data.\n");
	msort(data,0,N-1);
//	puts("");

	for(i=0;i<N;i++){
		printf("%d\n",data[i]);
	}

	return 0;
}

void msort(int data[],int left,int right){
	
	int m,buf,i,j,z;

	if(left==right)return;

	m=(left+right)/2;
	msort(data,left,m);
	msort(data,m+1,right);

	for(i=m;i>=left;i--){
		buf=data[i];
		j=0;
		while(((i+j)<right)&&(buf>data[i+j+1])){
			data[i+j]=data[i+j+1];
			j++;
		}
		data[i+j]=buf;
	}
	return;
}
