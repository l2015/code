#include <stdio.h>
int main(){
	for (int l=1; l<=4; l++) {
		for (int l2=4; l2>=l; l2--) {
			printf(" ");
		}
		for (int s=1; s<=l*2-1; s++) {
			printf("*");
		}
		printf("\n");
	}
	for (int l=1; l<=3; l++) {
		for (int l2=0; l2<=l; l2++) {
			printf(" ");
		}
		for (int s=5; s>=l*2-1; s--) {
			printf("*");
		}
		printf("\n");
	}
	
}