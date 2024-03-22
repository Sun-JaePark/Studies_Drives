#include <stdio.h>

int main(void)
{
    long l;
		int i;
		short s;
		char c;
		double d;
		float f;
    printf("long : %zu\n", sizeof(l));
		printf("int : %zu\n", sizeof(i));
		printf("short : %zu\n", sizeof(s));
		printf("char : %zu\n", sizeof(c));
		printf("double : %zu\n", sizeof(d));
		printf("float : %zu\n", sizeof(f));
    return 0;
}
