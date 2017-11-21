#include <stdio.h>
#include <string.h>
#define BF 1
#define KMP 1
#define TEXT_LENGTH 64
#define PATN_LENGTH 16
int next[PATN_LENGTH];

/* ï∂éöóÒtextÇ©ÇÁï∂éöóÒpatternÇåüçıÇ∑ÇÈ(óÕÇ‹Ç©Çπñ@) */
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
			printf("%s.....success.\n",pattern);
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

/* Ç∏ÇÁÇµï\ÇçÏê¨Ç∑ÇÈ */
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
		i=0;
	while(next[i]!=-1){
		printf("next[%d] = %d\n",i,next[i]);
		i++;
	}
	return;
}

/* ï∂éöóÒtextÇ©ÇÁï∂éöóÒpatternÇåüçıÇ∑ÇÈ(KMPñ@) */
int kmp_search(char text[], char pattern[])
{
	int i=0,j=0,count=0,ans=0;
	char *pcache;

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
#if BF
	printf("--- B F ---\n");
	printf("pyokopyokomipyokopyokomepyokopyokopyokopyokomupyokopyoko\n");
	position = brute_force_search("pyokopyokomipyokopyokomepyokopyokopyokopyokomupyokopyoko", "pyokopyokomu");
	printf("position=%d\n",position);
#endif
#if KMP
	printf("--- KMP ---\n");
	init_next(pattern);
	printf("%s\n",text);
	position = kmp_search(text, pattern);
	printf("position=%d\n",position);
#endif
#if KMP
	printf("--- KMP ---\n");
	init_next("pyokopyokomu");
	printf("pyokopyokomipyokopyokomepyokopyokopyokopyokomupyokopyoko\n");
	position = kmp_search("pyokopyokomipyokopyokomepyokopyokopyokopyokomupyokopyoko", "pyokopyokomu");
	printf("position=%d\n",position);
#endif
	return 0;
}

