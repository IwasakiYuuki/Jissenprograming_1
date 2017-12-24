/* グラフ構造の深さ優先探索 */

#include<stdio.h>
#define TRUE      1
#define FALSE     0
#define MAX_SIZE 11

typedef struct character{
        int  no;                        /* キー */
        char name;                      /* 名前 */
        struct character *next_addr;    /* 次のデータのアドレス */
}CELL;

char *graph_data[] = {
        "CI",           /* A : C I */
        "DGH",          /* B : D G H */
        "ADG",          /* C : A D G */
        "BCHIJ",        /* D : B C H I J */
        "FHJ",         /* E : F H J */
        "EGK",         /* F : E G K */
        "BCF",        /* G : B C F */
        "BDEJ",         /* H : B D E J */
        "AD",           /* I : A D */
        "DEHK",        /* J : D E H K */
        "FJ"          /* K : F J */
};

CELL *adjacent[MAX_SIZE]; /* 隣接リスト */
int visited[MAX_SIZE]={0};
int path[MAX_SIZE]={-1};

/* リスト構造で並んでいる様子を表示する */
void disp(void) {
        int i = 0;
        CELL *current_addr;
        printf("隣接リスト:\n");
        for( i = 0; i < MAX_SIZE; i++ ){
                if( adjacent[i] != NULL ){
                        current_addr = adjacent[i];
                        do{
                                printf("-|%c|-",current_addr->name);
                                current_addr = current_addr->next_addr;
                        }while( current_addr != NULL );
                }
                printf("\n");
        }
}

/* データの追加 */
void add(int parent, int child) {
        CELL *p;
        CELL *q;
         p = (CELL *)malloc(sizeof(CELL));
        p->no = child;
        p->name = 'A' + child;
        p->next_addr = NULL;
         q = adjacent[parent];
        while ( q->next_addr != NULL ) {
                q = q->next_addr;
        }
        q->next_addr = p;
}

/* グラフの初期化 */
void init_graph(void) {
/* 実装せよ */
    int j=0,x=0;
    CELL *cache=NULL;

    for(x=0;x<MAX_SIZE;x++){
        cache=(CELL *)malloc(sizeof(CELL));
        cache->next_addr=NULL;
        cache->no=x;
        cache->name=(char)((int)'A'+x);
        adjacent[x]=cache;
        cache=NULL;
    }

    for(int i=0;i<MAX_SIZE;i++){
        j=0;
        while(*(graph_data[i]+j)!='\0'){
            add(i,(int)*(graph_data[i]+j)-(int )'A');
            j++;
        }
    }
    disp();
    return;
}

/* 経路の表示 */
void print_path(int num) {
        int i;
        for( i = 0; i <= num; i++ ){
                 printf("%c ", path[i] + 'A' );
        }
        printf("\n");
}

/* 経路の探索（深さ優先探索） */
void search(int num, int now, int end) {
/* 実装せよ */
	CELL *current;
	path[num]=adjacent[now]->no;
	visited[path[num]]=1;
	if(path[num]==end){
	    print_path(num);
	    visited[path[num]]=0;
	    return;
	}

	current=adjacent[now];
	while(current!=NULL){
	    if(visited[current->no]==0)
	        search(num+1,current->no,end);
	    current=current->next_addr;
	}
	visited[path[num]]=0;
	return;
	
}



/* メイン関数 */
int main(void) {
        init_graph();
        search( 0, 0, 10 );             /* A(0) から K(10) の経路 */
        return 0;
}
