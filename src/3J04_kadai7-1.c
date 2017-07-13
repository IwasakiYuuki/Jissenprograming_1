#include <stdio.h>
#include <stdlib.h>

#define N 1000000

int Cache[N]={0};

void msort(int data[],int left,int right);
void msort2(int data[],int left,int right);

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
	msort2(data,0,N-1);
//	puts("");

	for(i=0;i<N;i++){
		printf("%d\n",data[i]);
	}

	return 0;
}

void msort(int data[],int left,int right){
	
	int m,buf,i,j,z;
	register int *cache;

	if(left==right)return;

	m=(left+right)/2;
	msort(data,left,m);
	msort(data,m+1,right);

	for(i=m;i>=left;i--){
		cache=&data[i];
		buf=*cache;
		j=0;
		while(((i+j)<right)&&(buf>(*(cache+1)))){
			*cache=*(cache+1);
			cache++;
			j++;
		}
		*(cache)=buf;
	}
	return;
}

void msort2(int data[],int left,int right){
	
	int m,i,j,z;

	if(left>=right)return;

	m = (left+right)/2;
	
	msort2(data,left,m);
	msort2(data,m+1,right);

	for(i=left;i<=m;i++)Cache[i]=data[i];
	for(i=m+1,j=right;i<=right;i++,j--)Cache[i]=data[j];

	i=left;
	j=right;

	for(z=left;z<=right;z++){
		if(Cache[i]<=Cache[j]){
			data[z]=Cache[i];
			i++;
		}else{
			data[z]=Cache[j];
			j--;
		}
	}

	return;
}
