#include <stdio.h>

int main(int argc, char *argv[]) {
	char c[]={"hello\0world\n"};
	printf("%s\n",c);
}