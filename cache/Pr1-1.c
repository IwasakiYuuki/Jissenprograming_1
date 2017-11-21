#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* dev-c++�R���p�C���ł́C��L��"<"��">"��"stdio.h"�Ƃ̊ԂɃX�y�[�X�������
 *    �R���p�C�����ɕs����������邱�Ƃ�����̂ŁC�X�y�[�X�͓���Ȃ��悤�� */

#define LINEAR 1  /* 1:���`�T���C0:�񕪒T�� */
#define NORMAL 1  /* 1:�ʏ�ŁC  0:�ԕ���   */
#define LOOP   1  /* 1:���[�v�ŁC0:�ċA��   */

#define N  40000  /* �T�����郌�R�[�h�� (���ӁF���̒l"����"��ς��Ă��A���ۂ̌������R�[�h���͑����Ȃ��j */ 

/* ���`�T�� */
int l_search(int data[], int target)
{
	int i=0, count = 0;
#if NORMAL   /* �ʏ�� */
	for ( i = 0; i < N; i++ )
		if ( target == data[i] ) {
			return i;
		}
	return -1;
#else        /* �ԕ��� */
	/* �������� */
	/* data�̈�ԍŌ�ɔԕ���ǉ����� */
	/* ���[�v�ɔ�r�����͕s�v�i�f�[�^���Ɍ����L�[�������Ă������Ă��Ō�ɔԕ��͌����邩��j */
	/* �݂������烋�[�v�𔲂��� */
	/* �ԕ������݂���Ȃ�������-1��Ԃ� */
	/* �f�[�^���݂�������break�����Ƃ��̓Y�����̒l��Ԃ� */
	data[N] = target;

	while(target!=data[i])i++;

	if(i!=N)
		return i;
	else
		return -1;
	
#endif
}

/* �N�C�b�N�\�[�g */
void quick(int data[], int left, int right)
{

	/* �O���ō쐬����quick�֐����ė��p����(�ė��p�ɂ������ďC�����K�v�Ȃ�A�C����ɍė��p����) */
	/* �N�C�b�N�\�[�g���܂��������Ă��Ȃ��ꍇ�͊��ɂł��Ă�����̂ōł������\�[�g��p���Ă悢 */
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

/* �񕪒T�� */
int b_search(int data[], int low, int high, int target)
{
#if LOOP 
	/* ���[�v�o�[�W���� */
	/* �������� */
	/* low <= high �̊Ԃ̓��[�v�ilow > high�Ȃ猩����Ȃ������j */
	/* mid �� low �� high �̒��Ԓl���Z�b�g */
	/* data[mid] ��� target ����������� high �� mid-1 �� */
	/* data[mid] ��� target ���傫����� low �� mid+1 �� */
	/* data[mid] == target �������烋�[�v�𔲂��� */
	/* ���������Ȃ� mid ��Ԃ� */
	/* ������Ȃ������Ȃ� -1 ��Ԃ� */
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
	/* �ċA�o�[�W���� */
	/* �������� */
	/* low > high �Ȃ猩����Ȃ������Ƃ������Ƃ� -1 ��Ԃ� */
	/* mid �� low �� high �̒��Ԓl���Z�b�g */
	/* data[mid] ��� target ����������ΑO�������ōċA */
	/* data[mid] ��� target ���傫����Ό㔼�����ōċA */
	/* data[mid] == target �������猩�������Ƃ������Ƃ� mid ��Ԃ� */
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

/* ���C�� */
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
	for( target = N/2-20000; target < N/2+19999; target++ ) {  // �������R�[�h����ς���ɂ́A���̕ӂ���C������K�v������
#if LINEAR
		index = l_search(work,target);
#else
		index = b_search(work,0,N-1,target);
#endif
//		printf("TARGET=%d: ", target);
//		if ( index != -1 )
//			printf("��\n");
//		else
//			printf("�~\n");
	}
	end=clock();
	printf("%f\n",(double)(end-start)/(double)CLOCKS_PER_SEC);
	return 0;
}

