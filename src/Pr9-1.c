/* �O���t�\���̕��D��T�� */

#include<stdio.h>

#define TRUE            1
#define FALSE           0
#define MAX_SIZE        11

int adjacent[MAX_SIZE][MAX_SIZE]; /* �אڍs�� */
int visited[MAX_SIZE]={0};
int open_list[MAX_SIZE]; /* �L���[ */

// char *graph_data[] = {
//        "CI",           /* A : C I */
//        "DGH",          /* B : D G H */
//        "ADG",          /* C : A D G */
//        "BCHIJ",        /* D : B C H I J */
//        "FHJ",          /* E : F H J */
//        "EGK",          /* F : E G K */
//        "BCF",          /* G : B C F */
//        "BDEJ",         /* H : B D E J */
//        "AD",           /* I : A D */
//        "DEHK",         /* J : D E H K */
//        "FJ"            /* K : F J */
//};

char *graph_data[] = {
      "BEF",      /* A is B E F */
      "ACF",      /* B is A C F */
      "BDG",      /* C is B D G */
      "C",        /* D is C */
      "AFH",      /* E is A F H */
      "ABEGIJ",   /* F is A B E G I J */
      "CFJ",      /* G is C F J */
      "EI",       /* H is E I*/
      "FHJ",      /* I is F H J */
      "FGIK",     /* J is F G I K */
      "J"         /* K is J */
};


/* �O���t�̏����� */
void init_graph(void)
{
        /* �������� */
	int i=0,j=0;
	for(i=0;i<MAX_SIZE;i++){
		for(j=0;j<MAX_SIZE;j++){
			adjacent[i][j]=0;
		}
	}
	for(i=0;i<MAX_SIZE;i++){
		j=0;
		while(graph_data[i][j]!='\0'){
			adjacent[i][graph_data[i][j]-'A']=1;
			j++;
		}
	}
	
	return;
}

/* �L���[�̏����� */
void init_queue(int *q)
{
        int i;
        for( i = 0; i < MAX_SIZE; i++ ){
                q[i] = -1;
        }
}

/* �L���[�̕\�� */
void print_queue(int *q)
{
        int i;
        printf("{");
        for( i = 0; i < MAX_SIZE; i++ )
                if( q[i] != -1 )
                        printf("%c",q[i]+'A');
        printf("}\n");
}

/* �L���[�̒��Ƀf�[�^d�����݂��Ă��邩�ǂ������`�F�b�N */
int check_queue(int *q,int d)
{
        int i;
        for( i = 0; i < MAX_SIZE;i++ )
                if( q[i] == d ) return TRUE;
        return FALSE; 
}

/* �L���[�Ƀf�[�^������ */
void enqueue(int *q, int d)
{
        /* �������� */
	int i=0;
	while(1){
		if(*q=='\0'||*q==-1)break;
		q++;
	}
	if(*q=='\0')return;
	else{
		*q=d;
	}
	
	return;
}

/* �L���[����f�[�^�����o�� */
int dequeue(int *q)
{
	int i=0,j=0,cache;
        /* �������� */

	cache=*q;
	for(i=0;i<MAX_SIZE-1;i++){
		*(q+i)=*(q+i+1);
	}
	while(*(q+j)!=-1){
		if((j-1)>=0){
			*(q+j-1)=-1;
		}else{
			break;
		}
		j++;
	}
	
	return cache;
}

/* �o�H�̒T���i���D��T���j */
void search(int now, int end)
{
        /* �������� */
    int cache=0;
    int i=0,a=0;
    init_queue(open_list);
    enqueue(open_list,now);
	printf("searching ... %c\n",'A'+open_list[0]);
	printf("open_list = ");
	print_queue(open_list);    
	
	while(open_list[0]!=-1){
		cache=dequeue(open_list);
		if(visited[cache]==TRUE)continue;
		visited[cache]=TRUE;
		for(i=0;i<MAX_SIZE;i++){
			if(adjacent[cache][i]==1){
				if(visited[i]==TRUE||check_queue(open_list,i)==TRUE)continue;
				enqueue(open_list,i);
				printf("searching ... %c\n",'A'+i);
				printf("open_list = ");
				print_queue(open_list);
				if(i==end){
					printf("Found.\n\n");
					return;
				}
			}
		}
	
	}
	printf("Not Found.\n\n");
	return;
}

/* ���C���֐� */
int main(void)
{
		int i=0,j=0;
        init_graph();
        printf("�אڍs��F\n");
        for(i=0;i<MAX_SIZE;i++){
        	for(j=0;j<MAX_SIZE;j++){
        		printf("%d",adjacent[i][j]);
        	}
        	printf("\n");
        }
        search(0, 10 );         /* A ���� K �̌o�H */
        return 0;
}