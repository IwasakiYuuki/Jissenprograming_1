#include <stdio.h>
#include <stdlib.h>
#define BUF_SIZE 32

int checksp(char c)
{
	if(c==' '||c=='\t'||c=='\n')
		return 1;
	else 
		return 0;
}

void compress(char *s)
{
	char *p,*buf;
	int i=0,j=0;
	/* 行頭の空白を消去 */
	while( (checksp(*(s+j))||*(s+j)==','||*(s+j)=='.')&&*(s+j)!='\0'){
		j++;
	}

	p=(char *)malloc(200*sizeof(char));
	buf=p;

	/* 新しい文字列を作成していく */
	while( *(s+j+i)!='\0' ){
		if(*(s+i+j)!=' '){
			buf = p+i;
			if(*(s+j+i)=='\t'){
				j++;
				continue;
			}else if(*(s+i+j)=='\n'){
				j++;
				continue;
			}
		}else if(*(s+i+j)==' '){
			if(*(s+i+j+1)==' '||*(s+j+i+1)==','||*(s+j+i+1)=='.'||*(s+i+j+1)=='\t'||*(s+i+j+1)=='\n'){
				j++;
				continue;
			}
			*(p+i)=*(s+j+i);
		}
		*(p+i)=*(s+i+j);
		i++;
	}
	*(buf+1)='\0';
	do{
		*s=*p;
		s++;
		p++;
	}while(*p!='\0');
	*s='\0';
}


int main(void)
{
	char s[] = "     Nice to \n meet \t you    ,  Jack !\n     I'm      Mike \n\t\t .    ";
	printf("%x\n",s);
	printf("Before = \"%s\"\n",s);
	compress(s);
	printf("After  = \"%s\"\n",s);

	return 0;
}
