#include <stdio.h>
#include <time.h>
int main() {
	clock_t start, end;
	
	
	int a[5000];
	int i;
	printf("please enter 10 integer numbers: ");
	for (i=0; i<5000; i++) {
		a[i]=i;
	}
	start = clock();
	for (i=0; i<5000; i++) {
		printf("%d",a[i]);
	}
	printf("\n");
	
	end = clock();
	printf("\ntime=%f\n", (double)(end - start)/CLOCKS_PER_SEC);
	return 0;
}