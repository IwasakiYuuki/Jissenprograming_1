#include <stdio.h>

#define N 10

void bablesort(int *num);

int main(){
	
	int num[N]={0},i;
//	int buffer=0,count=0;
	
	printf("������%d���͂��Ă�������\n",(int )N);
	for(i=0;i<N;i++){
		printf("%2d�� ==> ",i+1);
		scanf("%d",&num[i]);
	}

/*	do{
		count=0;	
		for(i=0;i<(N-1);i++){
			if(num[i]>num[i+1]){
				buffer=num[i];
				num[i]=num[i+1];
				num[i+1]=buffer;
				count++;
			}
		}
	}while(count!=0);*/
	
	bablesort(num);
	
	printf("\n�\�[�g����\n");
	for(i=0;i<N;i++)printf("%d ",num[i]);
	
	return 0;
}

void bablesort(int *num){
	int buffer=0,i,j;
	
	for(j=1;j<N;j++){
		for(i=0;i<(N-j);i++){
			if(num[i]>num[i+1]){
				buffer=num[i];
				num[i]=num[i+1];
				num[i+1]=buffer;
			}
		}
	}

	return;
}
