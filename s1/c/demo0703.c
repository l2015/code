#include <stdio.h>

int main(int argc, char *argv[]) {
	int max(float x,float y);
	float a,b;
	int c;
	printf("please enter two integer numbers:");
	scanf("%f,%f",&a,&b);
	c=max(a, b);
	printf("max is %d\n",c);
	return 0;
}

int max(float x,float y){
	float z;
	z=x>y? x:y;
	return z;
}