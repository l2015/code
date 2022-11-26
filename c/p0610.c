#include <stdio.h>
#include <stdlib.h>
#define arr letList[m][n] 
int main(int argc, char *argv[]) {
	char letList[3][80];

	for (int i=0; i<3; i++) {
		printf("请输入第%d行字符:",i+1);
		fgets(letList[i], 80, stdin);
	}
	int let=0,Let=0,num=0,space=0,other=0;
	for (int m=0; m<3; m++) {
		for (int n=0; arr!='\0' ; n++) {
			if (arr>='A'&&arr<='Z') {
				Let++;
			}else if (arr>='a'&&arr<='z') {
				let++;
			}else if (arr==' ') {
				space++;
			}else if (arr>='0'&&arr<='9') {
				num++;
			}else {
				other++;
			}
		}
	}
	printf("大写字母：%d\n小写字母：%d\n数字：%d\n空格：%d\n其它字符：%d\n",Let,let,num,space,other);
}