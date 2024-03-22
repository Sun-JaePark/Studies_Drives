#include <stdio.h>

int main()
{
		int v = 100;
		int *p = &v;
		printf("%p\n", p);
		int *q = p + 1;
		printf("%p", q);
		return 0;
}
