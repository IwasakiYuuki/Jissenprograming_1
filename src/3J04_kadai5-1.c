#include <stdio.h>
#include <stdlib.h>

#define N 100

void quicksort(int d[N],int a,int b);

int main(){
	
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
	

//	for(i=0;i<N;i++){
//		printf("%d\n",data[i]);
//	}


	quicksort(data,0,N-1);

	for(i=0;i<N;i++){
		printf("%d\n",data[i]);
	}

	return 0;
}

void quicksort(int d[N],int a,int b){
	int buf,first_a,first_b;
	if(a>=b)return;
	first_a=a;
	first_b=b;
	while(1){
		while(a<b&&d[a]<=d[first_a])a++;
		while(a<b&&d[b]>d[first_a])b--;
		if(a>=b)break;
		buf=d[a];
		d[a]=d[b];
		d[b]=buf;
	}
	a--;
	buf=d[first_a];
	d[first_a]=d[a];
	d[a]=buf;
	quicksort(d,first_a,a);
	quicksort(d,a+1,first_b);
	return;
}
