#include <stdio.h>

int main()
{
	for (int i = 0; i <= 100; i = i + 10)
	{
		int y = (i - 32) * 5 / 9;
		printf_s("%d test %d\n", i, y);
	}
	return 0;
}