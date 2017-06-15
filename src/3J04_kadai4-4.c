#include <stdio.h>

int decToBin(int n);

int main(){
		
	int buf;
	scanf("%d",&buf);

	printf("%d : %d\n",buf,decToBin(buf));

	return 0;
}

int decToBin(int n){
	
	if(n==1)return n%2;
	return (n%2)+decToBin(n/2)*10;
}
