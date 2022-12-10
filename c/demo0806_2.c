#include <stdio.h>

int main() {
	int a[10];
	int *p,i;
	printf("please enter 10 integer numbers: ");
	for (i=0; i<10; i++) {
		scanf("%d",&a[i]);
	}
	for (i=0; i<10; i++) {
		printf("%d",*p);
	}
	printf("\n");
	return 0;
}