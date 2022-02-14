#include <stdio.h>

int main(void) {

	double n;
	
	while(scanf("%lf",&n)==1) {
		printf("%g\n",n-1);
	}
	
	return 0;
}