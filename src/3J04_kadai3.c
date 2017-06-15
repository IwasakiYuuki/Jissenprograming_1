#include <stdio.h>

#define N 100
#define FILENAME "kadai-1-3.txt"
#define errorout(a) printf("error : %s",a)

void insertsort(int *num);
void new_insertsort(int *num);

int main(){
	
//	int i=0,firstBuf=0,secondBuf=0,buffer=0,count;
	int num[N]={0};
	FILE *fp_r;
	int size=0,i;
	
	fp_r=fopen(FILENAME,"r");
	if(fp_r==NULL)errorout("cant open file...\n");
	
	while(fscanf(fp_r,"%d",&num[size])!=EOF){
		size++;
	}
	
/*	do{
		count=0;
		for(i=0;i<N-2;i++){
			firstBuf=num[i];
			secondBuf=num[i+1];
			if(firstBuf>num[i+2]&&secondBuf>num[i+2]){
				buffer=num[i];
				num[i]=num[i+2];
				num[i+2]=num[i+1];
				num[i+1]=buffer;
				count++;
			}else if(secondBuf>num[i+2]&&firstBuf<=num[i+2]){
				buffer=num[i+1];
				num[i+1]=num[i+2];
				num[i+2]=buffer;
				count++;
			}else if(firstBuf>num[i+2]&&secondBuf<=num[i+2]){
				buffer=num[i+2];
				num[i+2]=num[i];
				num[i]=num[i+1];
				num[i+1]=buffer;
				count++;
			}else if(firstBuf<=num[i+2]&&secondBuf>num[i+2]){
				buffer=num[i+1];
				num[i+1]=num[i+2];
				num[i+2]=buffer;
				count++;
			}
		}
	}while(count!=0);*/
	
	new_insertsort(num);
	
	printf("\nÉ\Å[ÉgäÆóπ\n");
	for(i=0;i<N;i++){
		printf("%3d ",num[i]);
		if((i+1)%25==0)puts(" ");
	}
	return 0;
}

void insertsort(int *num){
	int i=0,firstBuf=0,secondBuf=0,buffer=0,count;
	
	do{
		count=0;
		for(i=0;i<N-2;i++){
			firstBuf=num[i];
			secondBuf=num[i+1];
			if(firstBuf>num[i+2]&&secondBuf>num[i+2]){
				buffer=num[i];
				num[i]=num[i+2];
				num[i+2]=num[i+1];
				num[i+1]=buffer;
				count++;
			}else if(secondBuf>num[i+2]&&firstBuf<=num[i+2]){
				buffer=num[i+1];
				num[i+1]=num[i+2];
				num[i+2]=buffer;
				count++;
			}else if(firstBuf>num[i+2]&&secondBuf<=num[i+2]){
				buffer=num[i+2];
				num[i+2]=num[i];
				num[i]=num[i+1];
				num[i+1]=buffer;
				count++;
			}else if(firstBuf<=num[i+2]&&secondBuf>num[i+2]){
				buffer=num[i+1];
				num[i+1]=num[i+2];
				num[i+2]=buffer;
				count++;
			}
		}
	}while(count!=0);
	
	return;
}

void new_insertsort(int *num){
	
	int i,j,buf,count=0;

	do{
		count=0;
		for(i=0;i<N-2;i++){
			
			if(num[i]>num[i+1]){
				buf=num[i];
				num[i]=num[i+1];
				num[i+1]=num[i];
				count++;
			}
			if(num[i]>num[i+2]){
				buf=num[i+2];
				num[i+2]=num[i+1];
				num[i+1]=num[i];
				num[i]=buf;
				count++;
			}else if(num[i+1]>num[i+2]){
				buf=num[i+2];
				num[i+2]=num[i+1];
				num[i+1]=buf;
				count++;
			}

		}
	}while(count!=0);

	return;
}
