/* 2•ª’Tõ–Ø‚É‚æ‚é’Tõ */

#include <stdio.h>

#define KEY_SIZE	8

struct tree{
	struct tree *left;
	int no;
	struct tree *right;
};

/* ”’l‚Ì“ü—Í—pŠÖ” */
int get_num(void) {
	int  i;
	int  d = 0;
	int  c = 0;
	rewind(stdin);
	for( i = 0; i < 5 && c != '_n' ; i++ ){ /* 5ƒPƒ^‚Ü‚Å */
		c = getchar();
		if ( c == '_n' ) break;
		d = d * 10 + c - '0';
	}
	rewind(stdin);
	return d;
}

void get_char(char *str){
	char c;
	int cnt=0;
	while(1){
		c = getchar();
		str[cnt]=c;
		if(c=='_n'){
			str[cnt]='_0';
			return;
		}
		cnt++;
	}
	return;
}

/* ƒm[ƒh‚Ì’Ç‰Á */
struct tree *add_node(int num) {
	struct tree *p;
	p = (struct tree *)malloc(sizeof(struct tree));
	p->left = NULL;
	p->no = num;
	p->right = NULL;
	return p;
}

/* ƒcƒŠ[‚Ìì¬ */
struct tree *make_tree(struct tree *node, int num) {
	if( node == NULL ){
		node = add_node(num);
		return node;
	}
	if ( num > node->no )
		node->left = make_tree(node->left,num);
	if ( num < node->no )
		node->right = make_tree(node->right,num);
	return node;
}

/* ƒcƒŠ[‚Ì•\¦ */
void print_tree(struct tree *node) {
	int i;
	static int depth = 0;
	if( node->left != NULL ){
		depth ++;
		print_tree(node->left);
		depth --;
	}
	for( i = 0; i < depth; i++ )
		printf("_t");
	printf("[%2d]_n",node->no);
	if( node->right != NULL){
		depth ++;
		print_tree(node->right);
		depth --;
	}
}

/* ƒcƒŠ[‚Ì’TõŠÖ” search ‚ğÀ‘• */
void search(struct tree *pos,int key){
	if(pos==NULL){
		printf("Not Found._n");
		return;
	}else if(pos->no == key){
		printf("[%d]->Found._n",key);
		return;
	}else if(pos->no < key){
		printf("[%d]->",pos->no);
		search(pos->left,key);
		return;
	}else if(pos->no > key){
		printf("[%d]->",pos->no);
		search(pos->right,key);
		return;
	}
	return;
}


int main(void) {
	struct tree *root;
	int i, num,key;
	char c[] = "";
	char ans[256],endflag=0;


	for( i = 0; i < KEY_SIZE; i++ ){
		printf("%d> ",i+1);
		num = get_num();
		if( i == 0 ){
			root = make_tree(NULL,num);
		}
		else{
			make_tree(root,num);
		}
	}
	print_tree(root);

	/* ƒL[“ü—Í‚É‚æ‚èÀs‚ª’â~‚³‚ê‚é‚Ü‚ÅA’TõƒL[‚Ì
	 *          * “ü—Í‚Æ’TõAŒ‹‰Ê‚Ì•\¦‚ğŒJ‚è•Ô‚·
	 *                   */
	while(endflag==0){
		printf("key>");
		key = get_num();
		search(root,key);
		printf("Do you wanna continue(yes/no)?");
		while(1){
			get_char(ans);
			if(!strcmp(ans,"yes")){
				break;
			}else if(!strcmp(ans,"no")){
				endflag=1;
				break;
			}else{
				puts("pls input only (yes/on).");
			}
		}
	}


	return 0;
}
