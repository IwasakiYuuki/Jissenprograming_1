#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int reverse(int *num,int file_count);
int insertsort(int *num,int file_count);
int selectsort(int *num,int file_count);
int bablesort(int *num,int file_count);
int countnum(FILE *fp);

int main(){
	
	FILE *fp_r,*fp_w;
	char filename[128]="";
	int sort,scend;
	int *num;
	int i=0,count=0,ex_count=0;
	
	printf("Pls input filename>>");
	scanf("%s",filename);
	fp_r=fopen(filename,"r");
	if(fp_r==NULL)puts("Error : cannot open file...");
	count=countnum(fp_r);
	num=(int *)malloc(sizeof(int)*count);
	for(i=0;i<count;i++){
		fscanf(fp_r,"%d",&num[i]);
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
				ex_count=bablesort(num,count);
				break;
			case 2:
				ex_count=selectsort(num,count);
				break;
			case 3:
				ex_count=insertsort(num,count);
				break;
			default:
				puts("Pls input another number...");
				goto input_sort;
		}
	}else if(scend==2){
		switch(sort){
			case 1:
				ex_count=bablesort(num,count);
				break;
			case 2:
				ex_count=selectsort(num,count);
				break;
			case 3:
				ex_count=insertsort(num,count);
				break;
			default:
				puts("Pls input another number...");
				goto input_sort;
		}
		ex_count+=reverse(num,count);
	}

//	for(i=0;i<count;i++){
//		printf("%d  ",num[i]);
//	}
	
	printf("Exchange count : %d\n",ex_count);

	strcat(filename,"a");
	fp_w=fopen(filename,"w");

	for(i=0;i<count;i++){
		fprintf(fp_w,"%d\n",num[i]);
	}
	free(num);
	return 0;
}

int reverse(int *num,int file_count){
	int i,buf=0,ex_count=0;
	
	for(i=0;i<file_count/2;i++){
		buf=num[i];
		num[i]=num[99-i];
		num[99-i]=buf;
		ex_count+=1;
	}
	return ex_count;
}

int insertsort(int *num,int file_count){
	int i=0,firstBuf=0,secondBuf=0,buffer=0,count,ex_count=0;
	
	do{
		count=0;
		for(i=0;i<file_count-2;i++){
			firstBuf=num[i];
			secondBuf=num[i+1];
			if(firstBuf>num[i+2]&&secondBuf>num[i+2]){
				buffer=num[i];
				num[i]=num[i+2];
				num[i+2]=num[i+1];
				num[i+1]=buffer;
				count++;
				ex_count+=2;
			}else if(secondBuf>num[i+2]&&firstBuf<=num[i+2]){
				buffer=num[i+1];
				num[i+1]=num[i+2];
				num[i+2]=buffer;
				count++;
				ex_count+=1;
			}else if(firstBuf>num[i+2]&&secondBuf<=num[i+2]){
				buffer=num[i+2];
				num[i+2]=num[i];
				num[i]=num[i+1];
				num[i+1]=buffer;
				count++;
				ex_count+=2;
			}else if(firstBuf<=num[i+2]&&secondBuf>num[i+2]){
				buffer=num[i+1];
				num[i+1]=num[i+2];
				num[i+2]=buffer;
				count++;
				ex_count+=1;
			}
		}
	}while(count!=0);
	
	return ex_count;
}

int selectsort(int *num,int file_count){
	int i=0,buffer=0,count=0,num_buffer=0,first_buf=0,ex_count=0;
	
	buffer=num[0];
	
	do{
		first_buf=num[count];
		for(i=0;i<=file_count-count;i++){
			if(buffer>=num[i+count]){
				buffer=num[i+count];
				num_buffer=i+count;
				ex_count+=1;
			}
		}
		num[count]=buffer;
		count++;
		buffer=num[count];
		num[num_buffer]=first_buf;
	}while(count!=file_count);
	return ex_count;
}

int bablesort(int *num,int file_count){
	int buffer=0,count=0,i,ex_count=0;
	
	do{
		count=0;	
		for(i=0;i<(file_count-1);i++){
			if(num[i]>num[i+1]){
				buffer=num[i];
				num[i]=num[i+1];
				num[i+1]=buffer;
				count++;
				ex_count+=1;
			}
		}
	}while(count!=0);
	
	return ex_count;
}

int countnum(FILE *fp){
	int count=0,num;

	while(fscanf(fp,"%d",&num)!=EOF){
		count++;
	}
	rewind(fp);
	return count;
}
