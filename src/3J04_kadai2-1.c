#include <stdio.h>
#include <stdlib.h>

void sharker_sort(int *num,int count);
int countnum(FILE *fp);

int main(){
	FILE *fp_r;
	char filename[128];
	int count=0;
	int *num,i;

	printf("Pls input filename >>");
	scanf("%s",filename);
	fp_r=fopen(filename,"r");
	if(fp_r==NULL)puts("Error : cannot open file...");
	count=countnum(fp_r);
//	printf("%d\n",count);
	num=(int *)malloc(sizeof(int)*count);
	for(i=0;i<count;i++){
		fscanf(fp_r,"%d",&num[i]);
	}

	sharker_sort(num,count);

	for(i=0;i<count;i++){
		printf("%3d ",num[i]);
		if((i+1)%14==0)puts(" ");
	}
	puts(" ");
	return 0;
}

void sharker_sort(int *num,int count){
	int j=0,i=0,left=0,right,buf,ex_count=0;
	int cache=0;

	right=count;

	do{
		ex_count=0;
		if(j%2==0){
			cache=right;
			for(i=0;i<(right-left);i++){
				if(num[left+i]>num[left+i+1]){
					buf=num[left+i];
					num[left+i]=num[left+i+1];
					num[left+i+1]=buf;
					ex_count++;
					cache=left+i;
				}
			}
			right=cache;
		}else{
			cache=left;
			for(i=0;i<right-left;i++){
				if(num[right-i]<num[right-i-1]){
					buf=num[right-i];
					num[right-i]=num[right-i-1];
					num[right-i-1]=buf;
					cache=right-i;
					ex_count++;
				}
			}
			left=cache;
		}
		j++;
	}while(ex_count!=0);

	if(num[left]>num[right]){
		buf=num[left];
		num[left]=num[right];
		num[right]=buf;
	}


	return;
}

int countnum(FILE *fp){
	int count=0,num;

	while(fscanf(fp,"%d",&num)!=EOF){
		count++;
	}
	rewind(fp);
	return count;
}
