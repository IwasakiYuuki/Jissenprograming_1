/* グラフ構造の幅優先探索 */

#include<stdio.h>

#define TRUE            1
#define FALSE           0
#define MAX_SIZE        11

int adjacent[MAX_SIZE][MAX_SIZE]; /* 隣接行列 */
int visited[MAX_SIZE]={0};
int open_list[MAX_SIZE]; /* キュー */

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


/* グラフの初期化 */
void init_graph(void)
{
        /* 実装せよ */
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

/* キューの初期化 */
void init_queue(int *q)
{
        int i;
        for( i = 0; i < MAX_SIZE; i++ ){
                q[i] = -1;
        }
}

/* キューの表示 */
void print_queue(int *q)
{
        int i;
        printf("{");
        for( i = 0; i < MAX_SIZE; i++ )
                if( q[i] != -1 )
                        printf("%c",q[i]+'A');
        printf("}\n");
}

/* キューの中にデータdが存在しているかどうかをチェック */
int check_queue(int *q,int d)
{
        int i;
        for( i = 0; i < MAX_SIZE;i++ )
                if( q[i] == d ) return TRUE;
        return FALSE; 
}

/* キューにデータを入れる */
void enqueue(int *q, int d)
{
        /* 実装せよ */
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

/* キューからデータを取り出す */
int dequeue(int *q)
{
	int i=0,j=0,cache;
        /* 実装せよ */

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

/* 経路の探索（幅優先探索） */
void search(int now, int end)
{
        /* 実装せよ */
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

/* メイン関数 */
int main(void)
{
		int i=0,j=0;
        init_graph();
        printf("隣接行列：\n");
        for(i=0;i<MAX_SIZE;i++){
        	for(j=0;j<MAX_SIZE;j++){
        		printf("%d",adjacent[i][j]);
        	}
        	printf("\n");
        }
        search(0, 10 );         /* A から K の経路 */
        return 0;
}