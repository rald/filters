#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>



char *prepend(char **s,const char *f,...) {

	va_list a;

	int blen1,blen2,blen3;

	char *buf1=NULL,*buf2=NULL,*buf3=NULL;

	if(*s!=NULL) {

		blen1=snprintf(NULL,0,"%s",*s);

		va_start(a,f);
			blen2=vsnprintf(NULL,0,f,a);
		va_end(a);

		blen3=blen1+blen2;

		buf1=calloc(blen1+1,sizeof(*buf1));		
		buf2=calloc(blen2+1,sizeof(*buf2));		
		buf3=calloc(blen3+1,sizeof(*buf3));		

		snprintf(buf1,blen1+1,"%s",*s);

		va_start(a,f);
			vsnprintf(buf2,blen2+1,f,a);
		va_end(a);

		snprintf(buf3,blen3+1,"%s%s",buf2,buf1);

		*s=realloc(*s,sizeof(*s)*(blen3+1));

		strncpy(*s,buf3,blen3+1);

		free(buf3);
		buf3=NULL;

		free(buf2);
		buf2=NULL;
		
		free(buf1);
		buf1=NULL;

	} else {

		va_start(a,f);
			blen3=vsnprintf(NULL,0,f,a);
		va_end(a);

		buf3=calloc(blen3+1,sizeof(*buf3));		

		va_start(a,f);
			vsnprintf(buf3,blen3+1,f,a);
		va_end(a);

		(*s)=calloc(blen3+1,sizeof(*s));

		strncpy(*s,buf3,blen3+1);

		free(buf3);
		buf3=NULL;

	}	

	return *s;
}


char *dec2bin(long d) {
	char *b=NULL;
	if(d>=0) {
		do {
			prepend(&b,"%ld",d%2);
			d/=2;
		} while(d);
	}
	return b;
}

int main(void) {

	long n;

	while(scanf("%ld",&n)==1) {
		char *b=dec2bin(n);
		if(b!=NULL) {
			printf("%s\n",b);
		} else {
			break;
		}
	}
	
	return 0;
}
