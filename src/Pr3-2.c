#include <stdio.h>
#define BF 1
#define KMP 1
#define BM 1
#define TEXT_LENGTH 64
#define PATN_LENGTH 256
int next[PATN_LENGTH];
/* テキストとパターンの不一致が見つかったときにどれだけずらすかを示す表 */
int skip[PATN_LENGTH]={0};

#define uchar unsigned char
#define max(a,b) ((a)>(b)?a:b) /* 二つの数a,bのうち大きい方を返すマクロ */

int brute_force_search(uchar text[], uchar pattern[])
{
	int i=0,j=0,count;
	uchar *tcache,*pcache;
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
			printf("%s.....success.\n",pattern);
			break;
		}
		text = (uchar *)(++tcache);
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
void init_next(uchar pattern[])
{
	int i=0,j=0,count;
	uchar *cache;
	cache=pattern;
	while(*(pattern+j)!='\0'){
		
		for(i=1;i<j;i++)if(*(pattern+i)==*cache)break;
		
		next[j]=i;
		
		j++;
	}
	next[j]=-1;
		i=0;
	while(next[i]!=-1){
		printf("next[%d] = %d\n",i,next[i]);
		i++;
	}
	return;
}

/* 文字列textから文字列patternを検索する(KMP法) */
int kmp_search(uchar text[], uchar pattern[])
{
	int i=0,j=0,count=0,ans=0;
	uchar *pcache;

	pcache = pattern;
	while(*text!='\0'){
		count=0;
		while(*(text+count)!='\0'&&*(text+count)==*(pattern+count)){
			count++;
		}
		if(*(pattern+count)=='\0'){
			for(j=ans;j>0;j--){
				printf(" ");
			}
			pattern = pcache;
			printf("%s.....success.\n",pattern);
			break;
		}
		for(j=ans;j>0;j--){
			printf(" ");
		}
		for(j=count+1;j>0;j--){
			printf("%c",*pattern);
			pattern++;
		}
		pattern = pcache;
		puts(".....false.");
		ans+=next[count];
		text+=next[count];
	}
	if(*text=='\0')
		return -1;
	else
		return ans;
}


/* BM法用のずらし表を作成する */
void init_skip(uchar pattern[])
{
	int ptn_num=0,i,k,cnt;
	uchar fin[PATN_LENGTH];

	while(*pattern != '\0'){
		pattern++;
		ptn_num++;
	}
	
	for(i=0;i<PATN_LENGTH;i++){
		skip[i]=ptn_num;
	}

	pattern -= ptn_num;
	for(i=0;i<ptn_num;i++){
		cnt=0;
		k=0;
		while(cnt<ptn_num&&*(pattern+i)!=*(pattern+ptn_num-k)){
			cnt++;
			k++;
		}
		skip[*(pattern+i)]=cnt-1;
	}

	while(*pattern!='\0'){
		printf("%c: skip[%d] = %d\n",*pattern,(int)*pattern,skip[*pattern]);
		pattern++;
	}

	return;
}


/* 文字列textから文字列patternを検索する(BM法) */
int bm_search(uchar text[], uchar pattern[]) {
	
	int j=0,num = 0,i=0,t_num=0,p_pos =0;

	while(pattern[num]!='\0')num++;

	while(text[t_num]!='\0')t_num++;

	i = num - 1;
	while(i < t_num){
		
		p_pos = num - 1;
		for(j=0;j<i;j++)printf(">");
		while(p_pos >= 0 && i < t_num){
			if(text[i] == pattern[p_pos]){
				if(p_pos==(num-1)){
					printf("%c",pattern[p_pos]);
				}else{
					printf("\n");
					for(j=0;j<i;j++)printf(" ");
					printf("%c",pattern[p_pos]);
				}
				i--;
				p_pos--;
			}else{
				if(p_pos==(num-1)){
					printf("%c",pattern[p_pos]);
				}else{
					printf("\n");
					for(j=0;j<i;j++)printf(" ");
					printf("%c",pattern[p_pos]);
				}
				puts(".....false.");
				break;
			}
		}
		if(p_pos < 0){
			puts(".....success.");
			return i+1;
		}
		i += max(num-p_pos,skip[text[i]]);
	}
	return -1;
}


int main(void)
{
	uchar text[TEXT_LENGTH+1];
	uchar pattern[PATN_LENGTH+1];
	uchar text_2[TEXT_LENGTH+1];
	uchar pattern_2[PATN_LENGTH+1];
	int position;

	strcpy(text,"aabbabcabc");
	strcpy(pattern,"abcab");
	strcpy(text_2,"pyokopyokomipyokopyokomepyokopyokopyokopyokomupyokopyoko");
	strcpy(pattern_2,"pyokopyokomu");

#if BF
	printf("--- B F ---\n");
	printf("%s\n",text);
	position = brute_force_search(text, pattern);
	printf("position=%d\n",position);
	printf("\n%s\n",text_2);
	position = brute_force_search(text_2, pattern_2);
	printf("position=%d\n",position);
#endif

#if KMP
	printf("--- KMP ---\n");
	init_next(pattern);
	printf("%s\n",text);
	position = kmp_search(text, pattern);
	printf("position=%d\n",position);
	init_next(pattern_2);
	printf("\n%s\n",text_2);
	position = kmp_search(text_2, pattern_2);
	printf("position=%d\n",position);
#endif


#if BM
	printf("--- B M ---\n");
	init_skip(pattern);
	printf("%s\n",text);
	position = bm_search(text, pattern);
	printf("position=%d\n",position);
	init_skip(pattern_2);
	printf("\n%s\n",text_2);
	position = bm_search(text_2, pattern_2);
	printf("position=%d\n",position);
#endif

	return 0;
}
