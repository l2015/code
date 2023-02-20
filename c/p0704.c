#include <stdio.h>

int main(int argc, char *argv[])
{
	int arr[3][3];
	for (int i = 0; i < 3; i++)
	{
		printf("origin row %d : ", i + 1);
		scanf("%d,%d,%d", &arr[i][0], &arr[i][1], &arr[i][2]);
	}

	int trans(int x[3][3]);
	trans(arr);
}

int trans(int x[3][3])
{
	int temp[3][3];
	for (int m = 0; m < 3; m++)
	{
		printf("\ntrans row %d : ", m + 1);
		for (int n = 0; n < 3; n++)
		{
			temp[m][n] = x[n][m];
			printf("%d,", temp[m][n]);
		}
	}
	return 0;
}