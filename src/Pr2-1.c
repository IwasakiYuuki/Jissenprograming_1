
#include <stdio.h>
#include <string.h>
#define BF 1
#define KMP 0
#define TEXT_LENGTH 64
#define PATN_LENGTH 16
int next[PATN_LENGTH];

/* 文字列textから文字列patternを検索する(力まかせ法) */
int brute_force_search(char text[], char pattern[])
{
	int i=0,j=0,count;
	char *tcache,*pcache;
	pcache = pattern;
	while(*text!='\0'){
		count=0;
		tcache = text;
		while(*text!='\0'&&*text==*pattern){
			text++;
			pattern++;
			count++;
		}
		if(*pattern=='\0'){
			for(j=i;j>0;j--){
				printf(" ");
			}
			pattern = pcache;
			printf("%s.....succes.\n",pattern);
			break;
		}
		text = (char *)(++tcache);
		pattern = pcache;
		for(j=i;j>0;j--){
			printf(" ");
		}
		for(j=count+1;j>0;j--){
			printf("%c",*pattern);
			pattern++;
		}
		pattern = pcache;
		puts(".....false.");
		i++;
	}

	return i;
}

/* ずらし表を作成する */
void init_next(char pattern[])
{
	int i=0,j=0,count;
	char *cache;
	cache=pattern;
	while(*(pattern+j)!='\0'){
		
		for(i=1;i<j;i++)if(*(pattern+i)==*cache)break;
		
		next[j]=i;
		
		j++;
	}
	next[j]=-1;
	return;
}

/* 文字列textから文字列patternを検索する(KMP法) */
int kmp_search(char text[], char pattern[])
{
}

int main(void)
{
	char text[TEXT_LENGTH+1];
	char pattern[PATN_LENGTH+1];
	int position;
	strcpy(text,"xxxtartartayx");
	strcpy(pattern,"tartay");

#if BF
	printf("--- B F ---\n");
	printf("%s\n",text);
	position = brute_force_search(text, pattern);
	printf("position=%d\n",position);
#endif
	init_next(pattern);
	printf("%d\n",next[0]);
	printf("%d\n",next[1]);
	printf("%d\n",next[2]);
	printf("%d\n",next[3]);
	printf("%d\n",next[4]);
	printf("%d\n",next[5]);
	printf("%d\n",next[6]);
#if KMP
	printf("--- KMP ---\n");
	init_next(pattern);
	printf("%s\n",text);
	position = kmp_search(text, pattern);
	printf("position=%d\n",position);
#endif
	return 0;
}
