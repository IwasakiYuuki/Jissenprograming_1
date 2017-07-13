#include <stdio.h>

#define N 1000000

void mergesort(int data[],int left,int right);

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
	}

	for(i=0;i<N;i++){
		fscanf(fp,"%d",&data[i]);
	}
	mergesort(data,0,9);
//	puts("");

	for(i=0;i<10;i++){
		printf("%d\n",data[i]);
	}

	return 0;
}

void mergesort(int data[],int left,int right){
	
	int m,buf,i,j,z;

	if(left==right)return;

	m=(left+right)/2;
	
	printf("m=%d",m+1);

	mergesort(data,left,m);
	mergesort(data,m+1,right);

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
