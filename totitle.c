#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main(void) {

	int ch;
	bool inside=false;
	bool first=true;

	while((ch=getchar())!=EOF) {

		if(!inside && isalnum(ch)) { inside=true; first=true; }
		else if(inside && !isalnum(ch)) { inside=false; }

		if(inside && first) {
			first=false;
			putchar(toupper(ch));
		} else {
			putchar(tolower(ch));
		}
	}

	return 0;
}
