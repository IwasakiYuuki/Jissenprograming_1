#include <stdio.h>
#include <string.h>
#define N 100

//aaa

void reverse(int *num);
void insertsort(int *num);
void selectsort(int *num);
void bablesort(int *num);

int main(){
	
	FILE *fp_r,*fp_w;
	char filename[128]="";
	int sort,scend;
	int *num;
	int i=0;
	
	printf("Pls input filename>>");
	scanf("%s",filename);
	fp_r=fopen(filename,"r");
	if(fp_r==NULL)puts("Error : cannot open file...");
	while(fscanf(fp_r,"%d",&num[i])!=EOF){
		i++;
	}
	input_scend:
	printf("[1]ascending order [2]descending order...>>");
	scanf("%d",&scend);
	if(scend!=1&&scend!=2)goto input_scend;
	puts(" ");
	puts("Pls select sort...");
	puts("1 : bubble sort");
	puts("2 : select sort");
	puts("3 : insert sort");
	input_sort:
	printf(">>");
	scanf("%d",&sort);
	
	if(scend==1){
		switch(sort){
			case 1:
				bablesort(num);
				break;
			case 2:
				selectsort(num);
				break;
			case 3:
				insertsort(num);
				break;
			default:
				puts("Pls input another number...");
				goto input_sort;
		}
	}else if(scend==2){
		switch(sort){
			case 1:
				bablesort(num);
				break;
			case 2:
				selectsort(num);
				break;
			case 3:
				insertsort(num);
				break;
			default:
				puts("Pls input another number...");
				goto input_sort;
		}
		reverse(num);
	}

	for(i=0;i<N;i++){
		printf("%d  ",num[i]);
	}
	
	strcat(filename,"a");
	fp_w=fopen(filename,"w");
	i=0;

	for(i=0;i<N;i++){
		fprintf(fp_w,"%d\n",num[i]);
	}
	
	return 0;
}

void reverse(int *num){
	int i,buf=0;
	
	for(i=0;i<N/2;i++){
		buf=num[i];
		num[i]=num[99-i];
		num[99-i]=buf;
	}
	return;
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

void selectsort(int *num){
	int i=0,buffer=0,count=0,num_buffer=0,first_buf=0;
	
	buffer=num[0];
	
	do{
		first_buf=num[count];
		for(i=count;i<N;i++){
			if(buffer>num[i]){
				buffer=num[i];
				num_buffer=i;
			}
		}
		num[count]=buffer;
		count++;
		buffer=num[count];
		num[num_buffer]=first_buf;
	}while(count!=N);
	
	return;
}

void bablesort(int *num){
	int buffer=0,count=0,i;
	
	do{
		count=0;	
		for(i=0;i<(N-1);i++){
			if(num[i]>num[i+1]){
				buffer=num[i];
				num[i]=num[i+1];
				num[i+1]=buffer;
				count++;
			}
		}
	}while(count!=0);
	
	return;
}
