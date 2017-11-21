#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* dev-c++コンパイラでは，上記の"<"や">"と"stdio.h"との間にスペースを入れると
 *    コンパイル時に不具合が発生することがあるので，スペースは入れないように */

#define LINEAR 1  /* 1:線形探索，0:二分探索 */
#define NORMAL 1  /* 1:通常版，  0:番兵版   */
#define LOOP   1  /* 1:ループ版，0:再帰版   */

#define N  40000  /* 探索するレコード数 (注意：この値"だけ"を変えても、実際の検索レコード数は増えない） */ 

/* 線形探索 */
int l_search(int data[], int target)
{
	int i=0, count = 0;
#if NORMAL   /* 通常版 */
	for ( i = 0; i < N; i++ )
		if ( target == data[i] ) {
			return i;
		}
	return -1;
#else        /* 番兵版 */
	/* 実装せよ */
	/* dataの一番最後に番兵を追加する */
	/* ループに比較条件は不要（データ中に検索キーがあっても無くても最後に番兵は見つかるから） */
	/* みつかったらループを抜ける */
	/* 番兵しかみつからなかったら-1を返す */
	/* データがみつかったらbreakしたときの添え字の値を返す */
	data[N] = target;

	while(target!=data[i])i++;

	if(i!=N)
		return i;
	else
		return -1;
	
#endif
}

/* クイックソート */
void quick(int data[], int left, int right)
{

	/* 前期で作成したquick関数を再利用する(再利用にあたって修正が必要なら、修正後に再利用する) */
	/* クイックソートがまだ完成していない場合は既にできているもので最も速いソートを用いてよい */
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

/* 二分探索 */
int b_search(int data[], int low, int high, int target)
{
#if LOOP 
	/* ループバージョン */
	/* 実装せよ */
	/* low <= high の間はループ（low > highなら見つからなかった） */
	/* mid に low と high の中間値をセット */
	/* data[mid] より target が小さければ high を mid-1 に */
	/* data[mid] より target が大きければ low を mid+1 に */
	/* data[mid] == target だったらループを抜ける */
	/* 見つかったなら mid を返す */
	/* 見つからなかったなら -1 を返す */
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
	/* 再帰バージョン */
	/* 実装せよ */
	/* low > high なら見つからなかったということで -1 を返す */
	/* mid に low と high の中間値をセット */
	/* data[mid] より target が小さければ前半部分で再帰 */
	/* data[mid] より target が大きければ後半部分で再帰 */
	/* data[mid] == target だったら見つかったということで mid を返す */
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

/* メイン */
int main(void)
{
	int a[N+1] , i, target, work[N+1], index;
	clock_t start,end;

	start=clock();
	for( i = 0; i < N; i++ ) work[i] = rand() % N;
#if LINEAR
#else
	quick(work,0,N-1);
#endif
	for( target = N/2-20000; target < N/2+19999; target++ ) {  // 検索レコード数を変えるには、この辺りを修正する必要がある
#if LINEAR
		index = l_search(work,target);
#else
		index = b_search(work,0,N-1,target);
#endif
//		printf("TARGET=%d: ", target);
//		if ( index != -1 )
//			printf("○\n");
//		else
//			printf("×\n");
	}
	end=clock();
	printf("%f\n",(double)(end-start)/(double)CLOCKS_PER_SEC);
	return 0;
}

