#include <stdio.h>

int main(void) {

	double n,sum=0;

	while(scanf("%lf",&n)==1) {
		printf("%g\n",n);
		sum+=n;
	}
	printf("\n%g\n",sum);
	
	return 0;
}