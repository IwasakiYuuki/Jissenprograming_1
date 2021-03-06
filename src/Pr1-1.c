#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* dev-c++?R???p?C???????C???L??"<"??">"??"stdio.h"?????????X?y?[?X??????????
 *    ?R???p?C???????s?????????÷?????}?????????????C?X?y?[?X??????????????? */

#define LINEAR 0  /* 1:???`?T???C0:?????T?? */
#define NORMAL 1  /* 1:???????C  0:??????   */
#define LOOP   0  /* 1:???[?v???C0:???A??   */

#define N  20000  /* ?T?????????R?[?h?? (?????F?}???l"????"???????????A?????????????R?[?h????????????j */ 

/* ???`?T?? */
int l_search(int data[], int target)
{
	int i, count = 0;
#if NORMAL   /* ?????? */
	for ( i = 0; i < N; i++ ){
		if ( target == data[i] ) {
			return i;
		}
	}
	return -1;
#else        /* ?????? */
				    /* ???????? */
				    /* data?????????????????????????? */
				    /* ???[?v?????r???????s?v?i?f?[?^?????????L?[???????????????????????????????????????????j */
				    /* ???????????????[?v???????? */
				    /* ??????????????????????????-1?????? */
				    /* ?f?[?^??????????????break???????????Y???????l?????? */

	data[N] = target;

	while(target!=data[i])i++;

	if(i!=N)
		return i;
	else
		return -1;

#endif
}

/* ?N?C?b?N?_?[?g */
void quick(int data[], int left, int right)
{
	int buf,first_a,first_b,a,b;
	a=left;
	b=right;
	if(a>=b)return;
	first_a=a;
	first_b=b;
	while(1){
		while(a<b&&data[a]<=data[first_a])a++;
		while(a<b&&data[b]>data[first_a])b--;
		if(a>=b)break;
		buf=data[a];
		data[a]=data[b];
		data[b]=buf;
	}
	a--;
	buf=data[first_a];
	data[first_a]=data[a];
	data[a]=buf;
	quick(data,first_a,a);
	quick(data,a+1,first_b);
	return;
}

/* ?????T?? */
int b_search(int data[], int low, int high, int target)
{
#if LOOP 
	int ans=0,left=0,right=0,m=0,count=0;

	left=low;
	right=high;

	while(left<right){
		m=(left+right)/2;
		if(data[m]>target){
			right=m;
		}else if(data[m]<target){
			left=m;
		}else if(data[m]==target){
			return m;
		}
		count++;
		if(count>24)break;
	}
	return -1;
#else
	int mid=0;
	int left,right;
	left=low;
	right=high;

	if(left>=right)return -1;

	mid = (left+right)/2;

	if(data[mid]>target)return b_search(data,left,mid-1,target);
	if(data[mid]<target)return b_search(data,mid+1,right,target);

	if(data[mid]==target)return mid;

	return -1;
#endif

}

/* ???C?? */
int main(void)
{
	int a[N], i, target, work[N], index,j;
	clock_t start,end;

	start=clock();
	for( i = 0; i < N; i++ ) work[i] = rand() % N;
#if LINEAR
#else
	quick(work,0,N-1);
#endif
	for( target = N/2-5000; target < N/2+4999; target++ ) {  // ???????R?[?h???????????????A?}?????????C???????K?v??????
#if LINEAR
		index = l_search(work,target);
#else
		index = b_search(work,0,N-1,target);
#endif
		printf("TARGET=%d: ", target);
		
		if( index != -1 )
			printf("o_n");
		else
			printf("x_n");
	}
	end=clock();
	
	printf("[*]???s?Ê?x : %lf?b_n",(double)(end-start)/(double)CLOCKS_PER_SEC);

	return 0;
}
