#include <stdio.h>
#include <stdlib.h>

#define N 100
#define FILENAME "kadai-1-3.txt"
#define errorout(a) printf("error : %s",a)

void shellsort(int *num);

int main(){

	int num[N]={0};
	FILE *fp_r;
	int size=0,i;
	
	fp_r=fopen(FILENAME,"r");
	if(fp_r==NULL)errorout("cant open file...\n");
	
	while(fscanf(fp_r,"%d",&num[size])!=EOF){
		size++;
	}

	shellsort(num);

	for(i=0;i<N;i++){
		printf("%3d ",num[i]);
		if((i+1)%25==0)puts(" ");
	}

	return 0;
}

void shellsort(int *num){
	int next,h=1,count=0,i,j,k;
	

	while(h<N){
		h=h*3+1;
	}
	h=h/3;

	while(h>0){
		for(i=0;i<h;i++){
			for(j=h+i;j<N;j+=h){
				next=num[j];
				for(k=j;k>=h&&next<num[k-h];k-=h){
					num[k]=num[k-h];
				}
				num[k]=next;
			}
		}
		h=h/3;
	}

	return;
}


