#include <stdio.h>
#define N 10

void selectsort(int *num);

int main(){
	
	int num[N],i=0,buffer=0,count=0,num_buffer=0,first_buf=0;
	
	printf("%d�̐�������͂��Ă�������\n",(int )N);
	
	for(i=0;i<N;i++){
		printf("%d��-->",i+1);
		scanf("%d",&num[i]);
	}
	
/*	buffer=num[0];
	
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
	}while(count!=N);*/
	
	selectsort(num);
	
	printf("�\�[�g����\n");
	for(i=0;i<N;i++)printf("%d ",num[i]);
	
	return 0;
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
