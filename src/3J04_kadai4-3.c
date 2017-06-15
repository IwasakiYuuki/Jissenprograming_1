#include <stdio.h>

int sumSeries(int n);

int main(){
	
	int buf;
	scanf("%d",&buf);

	printf("%d  :  %d\n",buf,sumSeries(buf));

	return 0;
}

int sumSeries(int n){
	if(n==0)return 0;
	return n+sumSeries(n-1);
}
