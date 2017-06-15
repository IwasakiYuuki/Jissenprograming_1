#include <stdio.h>

int factorial(int n);

int main(){
	
	int buf;
	scanf("%d",&buf);
	printf("%d! =  %d\n",buf,factorial(buf));
	return 0;
}

int factorial(int n){
	if(n<=0)return 1;
	return factorial(n-1)*n;
}
