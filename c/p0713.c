#include <stdio.h>

int main() {
	double pn(double n,double x);
	double n, x, y;
	printf("n : ");
	scanf("%lf", &n);
	printf("x : ");
	scanf("%lf", &x);
	y = pn(n,x);
	printf("result : %f\n", y);
	return 0;
}

double pn(double n,double x){
	double f;
	if (x==0) {
		f=1;
	}else if (n==1) {
		f=x;
	}else if (n>=1) {
		f=((2*n-1)*x-pn(n-1, x)-(n-1)*pn(n-2, x))/n;
	}
	return f;
}