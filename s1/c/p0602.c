#include <stdio.h>

int main()
{
	int a[10] = {2, 35, 12, 11, 32, 1, 65, 6, 21, 8};
	int m, n, t;
	for (m = 0; m < 10; m++)
	{
		for (n = m; n < 10; n++)
		{
			if (a[n] > a[m])
			{
				t = a[m];
				a[m] = a[n];
				a[n] = t;
			}
		}
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
}