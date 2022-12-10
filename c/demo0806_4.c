#include <stdio.h>
#include <time.h>
int main() {
	clock_t start, end;
	
	
	int a[5000];
	int *p,i;
	printf("please enter 10 integer numbers: ");
	for (i=0; i<5000; i++) {
		a[i]=i;
	}
	start = clock();
	for (p=a; p<(a+5000); p++) {
		printf("%d",*p);
	}
	printf("\n");

	
	end = clock();
	printf("\ntime=%f\n", (double)(end - start)/CLOCKS_PER_SEC);
	return 0;
}